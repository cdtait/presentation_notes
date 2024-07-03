from confluent_kafka import Consumer
from avro.schema import Parse
from avro.datafile import DataFileReader
from avro.io import DatumReader

# Kafka configuration
kafka_config = {
    'bootstrap.servers': 'kafka-broker-1:9092,kafka-broker-2:9092,kafka-broker-3:9092',
    'group.id': 'my-consumer-group',
    'auto.offset.reset': 'earliest',  # Start from the beginning
}

# Path to your Avro schema file
schema_file = 'path/to/your/schema.avsc' 

# Load Avro schema
with open(schema_file, 'r') as f:
    schema = Parse(f.read())

# Create a Kafka consumer
consumer = Consumer(kafka_config)

# Subscribe to the topic
consumer.subscribe(['your_topic'])

# Continuously consume messages
while True:
    msg = consumer.poll(timeout=1.0)

    if msg is None:
        continue

    if msg.error():
        print(f'Consumer error: {msg.error()}')
        continue

    # Decode Avro message
    reader = DatumReader()
    with DataFileReader(msg.value(), reader) as reader:
        for record in reader:
            print(f'Received message: {record}')

    # Commit the offset
    consumer.commit(msg)

# Close the consumer
consumer.close()
