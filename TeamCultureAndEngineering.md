# Pricing - Culture and Engineering

## Culture
  
### Observations in Pricing
Looking at Teams behaviour and difficulties in change

#### Habits
* Default behaviour
* Patterns of behaviour bred from process driven dvelopemnet
* Many very smart people collectivly ineffective.
* Standups, Restrospectives, Big Agile, Epic Forest

#### Breaking the habits
Things we tried to break habit bring in better practices
##### Dave Farley workshops
  * Off the back of Dave Farley as guest spreaker at ECop
  * Very well received and appriciated
  * Sponsored by Piers
  * Outcome
    * Shift especially in unity towards more test driven development
    * Sceptism around Pair programming and trunk based development
##### Presentations
  * Several Gitlab and Automation - Craig
  * QA automation - Craig and Wojciech

#### Management
Things management can help with
  * Focus on Goals and Outcomes rather than process and mechanisms
  * Automation
  * Development collaboration 
  * Eliminate Very long Peer Reviewing times 
  * Team buy in at core as can't buy in from some other team
  * Priority driven development doesn't understand bigger picture
  * Open communication business to all connected parts of delivery
  * Sit with the business
  * Sit with other groups mix together at all levels especially when doig a large project

##### Whats holding Pricing back?
* Constant stream of project feature requirments
* Renovation not prioritized
* Flim Flam - project changing priorties and shifting the ficus at a distructive rate (Wasting enourmous and unaccounatble time and effort)
* Not getting one thing finished fast enough before business loses interest and then changes priority

#### What can we do?
Things that could make a difference

##### Throw out
These require radical shift and support from managment but doing do provide the space to do the stuff we want to bring in
* Technical stories
* Task based planning
* Specification
* Prescriptive standardization
* Buracractic Culture

##### Bring in
These are really stating the obvious and have been talking about it in pricing for at least a couple of years
* State what the user wants
* User Requirements
* Fast Feedback
* Incremental deliver
* Quality Assurance fo everyone
* You build it you run it
* Generative Culture
* Pair Programming
* Trunk based
* Pipeline cooperation between teams ie share the pipelines so to see examples Gitlab is too private!

### Project strategies
* Big projects - Collaboration at high level between deptaments done by technical people to solve technical challenges
* Technical leader ship with tech specialists

## Engineering

### Pricing
* Pricing are at the sharp end of delivering prices quickly, to a vey demanding audience capacity with short latency.
* C++ has been used to give the ability for hgh perfomance and capacity
* Most of the focus in IG is around client facing system and tradionally has taken all the time and efforts in developing infrastructure and devops around this

### Skill
* Pricing Teams have got very high degrees of craft when it comes to c++
* Unity has a good pakage mangemnet for c++
* Teams usually have lots of Unit Tests
* QA is involved expescally with usnit on testing the perfomance and integration
* In the past and still is a habit of writting the test after the code this is improving escpecially in Unity
* The code sofistication and best pratcices in c++ is high in all teams
* Teams are struggling to get focus to move away from Jenkins (as it just works, well barely works) to GitLab - This is because of PiS
* Unity has already got piplienes which work all the way up to releasing onto the package managment in artifactory
* Feature feature has been inhibitive to the transfomationally task to move aaway from old code and devel pakages

### Renovation
* CORBA is difficut to change due to lack of expertise even in the wider (outside IG) community
* Invision which are extremly difficult to chnage
* Architecture have set a plan which has been awaiting focus fora few years.
* Principle Engineering and Tech specialists could help forge the proofs and POC to gudie the tech that can transform:

### Observability
* Observability adoption slow and not supported well for c++
* Obseravabilty exists in Pricing - Is comprehensive and has existed for a good number of years
* Incorrect perception that Pricing, Market Making and Exposure have low Obseravability
* Just beacuase they are not all using the new SaaS obseravbility platform
* Generating SLO and SLA
* Had to be developed with high performacne in mind and has evolved to use its own Grafana and Influx metrics db
* Splunk logging - Pricing have their own high perfomance logging solution
* SaaS Grafana and metrics platform definitly does not fulfill the hight perfomance metric gathering and recording and granularity that Pricing has currently got with the self maintained

### Production deployment
#### Nomad - release orcestration
* Exposure and Market Making setting a good example and need to promote and share with Pricing
* Pricincig are sceptical on using Nomad for good reason that the standard way is to provide a Nomad cluster with virtual (VM) ware services. This may not be capabile enough to support the capacity, high perfomance needs that Pricing has.
* A solution to this is to allow bare metal clusters to be managed through Nomad - Pricing need support for this
  
#### Auto CRF
* Pipeline developed by Pricicpal engineers (mainly Henock and Michal Jurzynski) although many other inclund myself had a hand in it.
  * The disapointing thing is as usual tis is aimed a being sort of genertic but again focus has been on java and spring boot applications and c++ left out, this need to be done probably by me
  * Exposure have buit ther own Auto CRF libabry based on the original code that I, Henock and Michal did.
  * Exposure are using this and their own pipline. This may be more suited to
##### Pricing release tools
Pricing has a very old realese and deployment set of tools (xcon release) and are uniquely part of the distribution of release, mnotiory tools and verson management
This is a fundemntatl obstical in moving to a model of service based deployments such as Nomad (if we can allow bare metal clustering)

## References
* Accellerate - Gene Kim, Jez Humble, and Nicole Forsgren (DORA)
* The Devops Handbook - Gene Kim (Culture, Automation, Lean, Measure, Sharing - CALMS)
* David Farley - CD and Modern Software Engineering
* Karl Weiger - Creating a sofware Engineering Culture
* Westrum Model of Organistional Culture (Pathalogical, Buercratic, Generative)
* Team Topologies - Mathew Skelton
* Agile manifesto - A load of big software geezers



