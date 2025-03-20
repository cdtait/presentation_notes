#include <bits/stdc++.h>
using namespace std;

namespace CodilityDemo {
/*
 Write a function:

    int solution(vector<int> &A);

that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.

For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.

Given A = [1, 2, 3], the function should return 4.

Given A = [−1, −3], the function should return 1.

Write an efficient algorithm for the following assumptions:

        N is an integer within the range [1..100,000];
        each element of array A is an integer within the range [−1,000,000..1,000,000].


 */
int solution(vector<int> &A) {
	sort(A.begin(), A.end());
	auto last = std::unique(A.begin(), A.end());
	A.erase(last,A.end());
	int N = (int) A.size();
	if (N > 100000)
		return -1;
	if (N == 0)
		return -1;
	last = remove_if(A.begin(), A.end(), [](int x) {
		return x <= 0;
	});
	A.erase(last,A.end());
	int i = 0;
	for (; i < (int)A.size(); i++) {
		if (A[i] != i + 1) {
			break;
		}
	}

	return i+1;
}

int solution2(vector<int> &A) {
	sort(A.begin(), A.end());
	auto last = std::unique(A.begin(), A.end());
	last = remove_if(A.begin(), last, [](int x) {return x < 1;});
	auto N = *std::prev(last);
	decltype(N) i = 0;
	for (; i < N; i++) {
		if (A[i] != i + 1) {
			break;
		}
	}

	return i+1;
}

int solution3(std::vector<int> &A) {
    // Put all positive integers from the array into a hash set for O(1) lookup
    std::unordered_set<int> positives;
    for (int num : A) {
        if (num > 0) {
            positives.insert(num);
        }
    }

    // Search for the smallest positive integer that's not in the set
    // Starting from 1 and incrementing until we find a missing number
    int smallestMissing = 1;
    while (positives.find(smallestMissing) != positives.end()) {
        smallestMissing++;
    }

    return smallestMissing;
}

// Driver program to test above function
int test() {
	std::vector<int> A1={1, 3, 6, 4, 1, 2};
	auto s = solution(A1);
	assert(s==5);
	std::cout << "CodilityDemo A1={1, 3, 6, 4, 1, 2} solution = " << s << std::endl;
	A1={1, 3, 6, 4, 1, 2};
	std::cout << "CodilityDemo A1={1, 3, 6, 4, 1, 2} solution2 = " << solution2(A1) << std::endl;
	std::cout << "CodilityDemo A1={1, 3, 6, 4, 1, 2} solution3 = " << solution3(A1) << std::endl;

	std::vector<int> A2={0, 1, 2};
	std::cout << "CodilityDemo A2={0, 1, 2} solution = " << solution(A2) << std::endl;
	A2={0, 1, 2};
	std::cout << "CodilityDemo A2={0, 1, 2} solution2 = " << solution2(A2) << std::endl;
	std::vector<int> A3={-1, 1, 2};
	std::cout << "CodilityDemo A3={-1, 1, 2 solution = " << solution(A3) << std::endl;
	 A3={-1, 1, 2};
	std::cout << "CodilityDemo A3={-1, 1, 2 solution2 = " << solution2(A3) << std::endl;
	std::vector<int> A4={-2, -1};
	std::cout << "CodilityDemo A4={-2, -1} solution = " << solution(A4) << std::endl;
	A4={-2, -1};
	std::cout << "CodilityDemo A4={-2, -1} solution = " << solution2(A4) << std::endl;
	std::vector<int> A5={1, 2, 3, 4, 5, 6};
	std::cout << "CodilityDemo A5={1, 2, 3, 4, 5, 6}; solution = " << solution(A5) << std::endl;
	A5={1, 2, 3, 4, 5, 6};
	std::cout << "CodilityDemo A5={1, 2, 3, 4, 5, 6}; solution2 = " << solution2(A5) << std::endl;
	std::vector<int> A6={-1, -2, -2, 0, 1, 1, 3, 2, 2, 3};
	std::cout << "CodilityDemo A6={-1, -2, -2, 0, 1, 1, 3, 2, 2, 3} solution = " << solution(A6) << std::endl;
	A6={-1, -2, -2, 0, 1, 1, 3, 2, 2, 3};
	std::cout << "CodilityDemo A6={-1, -2, -2, 0, 1, 1, 3, 2, 2, 3} solution2 = " << solution2(A6) << std::endl;

	std::cout << "CodilityDemo A6={-1, -2, -2, 0, 1, 1, 3, 2, 2, 3} solution2 = " << solution3(A6) << std::endl;
	return 0;
}
}

namespace task1 {

// Merges 2 ints from chars and creates new number
// Almost like the merge part from merge sort
int solution_task1(int A, int B) {
	std::string a_str = std::to_string(A);
	std::string b_str = std::to_string(B);
	std::string result_str;

	auto a_str_it=a_str.begin();
	auto b_str_it=b_str.begin();
	auto a_str_end=a_str.end();
	auto b_str_end=b_str.end();

	// Do the main interleave or merge up to end of the smallest
	while(a_str_it != a_str_end && b_str_it != b_str_end) {
		result_str += *a_str_it++;
		result_str += *b_str_it++;
	}

	// Add any left over a still has more
	while(a_str_it != a_str_end) {
		result_str += *a_str_it++;
	}

	// Add any left over b still has more
	while(b_str_it != b_str_end) {
		result_str += *b_str_it++;
	}

	try {
		int res = std::stoi(result_str);
		return res;
	}
	catch(std::exception &e) {
		return -1;
	}

	return -1;
}

int test_solution_task1() {
	std::cout << solution_task1(12345,678) << std::endl;
	std::cout << solution_task1(12345,6780000) << std::endl;
	std::cout << solution_task1(0,0) << std::endl;
	std::cout << solution_task1(1,0) << std::endl;
	return 0;
}

int test() {
	return test_solution_task1();
}
}

namespace task3 {
bool solution_task3_v1(vector<int> &A) {
	// So what this appears to do
	// Is looks for the numeber of swaps it needs to do
	// in order to sort an array.
	// Simply here we swap and count.
	// There must be 2 element differences for each
	// swap so either 0 (no swaps) or 2 (1 swap) is
	// maximum allowed.

    // write your code in C++11 (g++ 4.8.2)
	std::vector<int> B(A);
	auto N=B.size();

    // vector length check
	if (N>100) {
		// Error
		return false;
	}

	std::stable_sort(B.begin(), B.end());

	int count=0;
	for (decltype(N) i=0; i<N; i++) {
		if (A[i]!=B[i]) {
			count++;
		}
		// integer range check
		if (A[i]<1 || A[i]>1e9) {
			// Error
			return false;
		}
	}

	// Returns if we did one or less swaps to sort.
	return count<=2;
}

void solution_task3_v2_swap(vector<int> &A,int i,int j) {
	auto t = A[i];
	A[i] = A[j];
	A[j] = t;
}

// Broken version, minimumSwaps is good example
// of counting swaps needed
bool solution_task3_v2(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
	/*
	 This is a sort of sorting algo test which  seems to count swaps
	 So if A is not sorted just say.
	 Not sure this is a good implementation I think it does not work
	 corrrectly so do not use!!!!!!!!!!
	 */
	auto N=A.size();

    // vector length check
	if (N>100) {
		// Error
		return false;
	}

	int count=0;
	auto current_index = 0;
	for (int i = 1; i < (int)N; ++i) {
		// integer range check
		if (A[i]<1 || A[i]>1e9) {
			// Error
			return false;
		}
		// Is value of first element greater than second?
		if (A[current_index] > A[i]) {
			// while this is the case move forward till
			// we find an element that is is not
			while (A[current_index] > A[i]) {
				// integer range check
				if (A[i]<1 || A[i]>1e9) {
					// Error
					return false;
				}
				++i;
			}
			// Now swap the item and set next test element
			// to the one swapped
			//solution_task3_v2_swap(A,current_index,--i);
			std::swap(A[current_index],A[--i]);
			// count the swap
			// Can't we just return here, if its just to
			// detect if there are any sorts to do?
			count++;
		}

		current_index = i;
	}

	// Returns if we did one or less swaps to sort.
	return not (count > 1);
}

#include <vector>

namespace Codility1 {
/*
 * Not sure what this does, wrote it for some reason
 * Test examples below should give it away
 * So is this just finding first positive not in sequence?
 */
int solution(vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)
	// removes -Ve values
	A.erase(std::remove_if(A.begin(), A.end(), [](int x) {
		return x < 0;
	}), A.end());
	std::sort(A.begin(), A.end());
	std::unique(A.begin(), A.end());

	int prev = 0;
	if (A.begin() != A.end()) {
		for (auto next : A) {
			if (next > 1000000)
				return 1;
			// Returns if next bigger than prev by more than 1
			if (next - prev > 1)
				return prev + 1;
			else
				prev = next;
		}

		return prev + 1;
	}

	return 1;
}

int test() {
	std::vector<int> A1 { 1, 3, 6, 4, 1, 2 };
	std::cout << "solution(A1):" << solution(A1) << std::endl;

	std::vector<int> A2 { 1, 2, 3 };
	std::cout << "solution(A2):" << solution(A2) << std::endl;

	std::vector<int> A3 { -1, -2, 1, 2, 3, 4, 5, 7, 8 };
	std::cout << "solution(A3):" << solution(A3) << std::endl;

	int s = 1000000;
	std::vector<int> A4(s + 1);
	std::iota(A4.begin(), A4.end(), -10);
	// tets by earsing a value to find
	A4.erase(A4.begin() + s / 2 + s / 4);
	std::cout << "solution(A4):" << solution(A4) << std::endl;

	std::vector<int> A5 { 3 };
	std::cout << "solution(A5):" << solution(A5) << std::endl;

	s = 2000100;
	std::vector<int> A6(s + 1);
	std::iota(A6.begin(), A6.end(), -1000000);
	A6.erase(A6.begin() + s / 2 + s / 4);
	std::cout << "solution(A6):" << solution(A6) << std::endl;

	s = 10;
	std::vector<int> A7(s);
	std::iota(A7.begin(), A7.end(), 999999);
	std::cout << "solution(A7):" << solution(A7) << std::endl;

	s = 200;
	std::vector<int> A8(s);
	std::iota(A8.begin(), A8.end(), 0);
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(A8.begin(), A8.end() - 100, g);
	std::shuffle(A8.end() - 101, A8.end(), g);
	std::cout << "solution(A8):" << solution(A8) << std::endl;

	return 0;
}

}
;

// This is a cycle graph
// Basically the number of nodes making up a swap node cycle is one less than the swaps need to sort
// So for every cycle we need to know the number of nodes in a cycle add the number of nodes less 1 for
// each cycle together i.e sum them.

// Its accurate to tell us the minimum total numbrr of swaps we need
// In the case of task 3, we just need to know if only one is required
// so a sort and stop at count over 1 is good enough in solution_task3_v1
// Also watch out, as is does not detect range check

// Function returns the minimum number of swaps
// required to sort the array
int minimumSwaps(std::vector<int> &arr,std::vector<pair<int, int>> &arrPos) {
	// Sort the array by array element values to
	// get right position of every element as second
	// element of pair.
	sort(arrPos.begin(), arrPos.end());

	// To keep track of visited elements. Initialize
	// all elements as not visited or false.
	auto n = (int) arr.size();
	vector<bool> vis(n, false);

	// Initialize result
	int ans = 0;

	// Traverse array elements
	for (int i = 0; i < n; i++) {
		// already swapped and corrected or
		// already present at correct pos
		if (vis[i] || arrPos[i].second == i)
			continue;

		// find out the number of  node in
		// this cycle and add in ans
		int cycle_size = 0;
		int j = i;
		while (!vis[j]) {
			vis[j] = 1;

			// move to next node
			j = arrPos[j].second;
			cycle_size++;
		}

		// Update answer by adding current cycle.
		if (cycle_size > 0) {
			ans += (cycle_size - 1);
		}
	}

	// Return result
	return ans;
}

bool solution_task3_v3(vector<int> &A) {
	// Create an array of pairs where first
	// element is array element and second element
	// is position of first element

	auto n = (int) A.size();
    // vector length check
	if (n>100) {
		// Error
		return false;
	}

	std::vector<pair<int, int>> arrPos(n, pair<int, int> { 0, 0 });
	for (int i = 0; i < (int) n; i++) {
		arrPos[i].first = A[i];
		arrPos[i].second = i;
	}

	return  not(minimumSwaps(A,arrPos) > 1);
}

int test_solution_task3_v1() {
	std::vector<int> A={1,5,3,3,7};
	std::cout << solution_task3_v1(A) << std::endl;
	A={1,3,5,3,4};
	std::cout << solution_task3_v1(A) << std::endl;
	A={1,3,5};
	std::cout << solution_task3_v1(A) << std::endl;
	A={1,0,5};
	std::cout << solution_task3_v1(A) << std::endl;
	A={1,3,5,(int)2e6};
	std::cout << solution_task3_v1(A) << std::endl;

	return 0;
}

int test_solution_task3_v2() {
	std::vector<int> A={1,5,3,3,7};
	std::cout << solution_task3_v2(A) << std::endl;
	A={1,3,5,3,4};
	std::cout << solution_task3_v2(A) << std::endl;
	A={1,3,5};
	std::cout << solution_task3_v2(A) << std::endl;
	A={1,0,5};
	std::cout << solution_task3_v2(A) << std::endl;
	A={1,3,5,(int)2e6};
	std::cout << solution_task3_v2(A) << std::endl;

	return 0;
}

int test_solution_task3_v3() {
	std::vector<int> A={1,5,3,3,7};
	std::cout << std::boolalpha << solution_task3_v3(A) << std::endl;
	A={1,3,5,3,4};
	std::cout << std::boolalpha << solution_task3_v3(A) << std::endl;
	A={1,3,5};
	std::cout << std::boolalpha << solution_task3_v3(A) << std::endl;
	A={1,0,5};
	std::cout << std::boolalpha << solution_task3_v3(A) << std::endl;
	A={1,3,5,(int)2e6};
	std::cout << std::boolalpha << solution_task3_v3(A) << std::endl;

	return 0;
}

int test() {
	//test_solution_task3_v2();
	test_solution_task3_v1();
	test_solution_task3_v3();
	return 0;
}

};

namespace task4 {

int solution_task4_v1(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
	std::vector<int> B(A);
	auto N=B.size();
	std::sort(B.begin(), B.end());
	auto last = std::unique(B.begin(), B.end());
	B.erase(last, B.end());

	int diff_index=-1;
	int min_diff=std::numeric_limits<int>::max();
	for (decltype(N) i=0; i<N; i++) {
		auto value = A[i];
		auto lower = std::lower_bound(B.begin(), B.end(), value);
		auto next_value=lower+1;
		int diff = std::abs(*lower-*next_value);
		if (diff < min_diff) {
			min_diff=diff;
			auto lower = std::lower_bound(A.begin(), A.end(), *next_value);
			// index of A for the pair value
			diff_index=lower-(A.begin()+i);
		}
	}

	return diff_index;
}

int test_solution_task4_v1() {
	std::vector<int> A={0,3,3,7,5,3,3,11,1};
	std::cout << solution_task4_v1(A) << std::endl;
	A={1,4,7,3,3,5};
	std::cout << solution_task4_v1(A) << std::endl;

	return 0;
}

// Could be something to do with distances between elements
// of same value grouped in a range
int solution(vector<int> & A) {
	// Look up from a value in vector to the indices
	// of the vector which have this value
	std::multimap<int, int> value2indices;
	auto N=A.size();
	for (decltype(N) i=0;i<N;i++) {
		//value2indices.insert(std::make_pair(A[i], i));
		value2indices.emplace(A[i],i);
	}

	for (auto index : value2indices) {
	    cout << index.first << " " << index.second << endl;
	}

	int result=std::numeric_limits<int>::max();
	for (decltype(N) i=0;i<N;i++) {
		auto index_value = A[i];
		// what is the next index value? Above this one
		// if this is 0 in example 1 should be next
		auto next_index =value2indices.upper_bound(index_value);
		auto next_index_range = value2indices.equal_range(next_index->first);

		for (auto nrit = next_index_range.first; nrit != next_index_range.second;++nrit) {
			std::cout << "value2indices[" << (*nrit).first << "]=" << (*nrit).second << endl;
			std::cout << "(" << i << ", " << (*nrit).second << ") "
					  << std::abs((*nrit).second - (int)i)
			<< std::endl;
			auto index_of_next_value = (*nrit).second;
			auto dist=std::abs<int>(index_of_next_value - i);
			if (dist<result) {
				result=dist;
			}
		}
	}

	std::cout << std::endl;

	return result;
}

int test()
{
	// So 0 is in correct place 0 0 index
	// 1 is at pos 7
	// Some sort of smallest distance
    vector<int> A = {0,3,3,5,7,3,11,1};
    std::cout << "A=[0,3,3,5,7,3,11,1]" << std::endl;
    cout << solution(A) << endl;

    return 0;
}
};

// Lesson 1 - Iterations
namespace BinaryGap {

int solution(int N) {
	if (N < 0) return 0;
	int gap = 0;
	bool previous_one = false;
	auto bit_test = N & 1;
	previous_one = bit_test;
	auto max_gap = gap;
	N = N >> 1;
	while (N > 0) {
		bit_test = N & 1;
		if (!bit_test and previous_one)
			gap++;
		else {
			previous_one = bit_test;
			gap = 0;
		}
		if (gap > max_gap) {
			max_gap = gap;
		}
		N = N >> 1;
	}
	return max_gap;
}

// Driver program to test above function
int test() {
	assert(2 == solution(9));
	assert(4 == solution(529));
	assert(1 == solution(20));
	assert(0 == solution(32));
	assert(0 == solution(0));
	assert(0 == solution(15));
	assert(0 == solution(2147483647));
	assert(0 == solution(2147483646));
	assert(1 == solution(2147483645));
	assert(0 == solution(3221225471));
	return 0;
}
};


// Lesson 2 Arrays
#include <cxxabi.h>

namespace CyclicRotation {
/*
An array A consisting of N integers is given. Rotation of the array means that each element is shifted right by one index,
and the last element of the array is moved to the first place.
For example, the rotation of array A = [3, 8, 9, 7, 6] is [6, 3, 8, 9, 7]
(elements are shifted right by one index and 6 is moved to the first place).

The goal is to rotate array A K times; that is, each element of A will be shifted to the right K times.

Write a function:

    vector<int> solution(vector<int> &A, int K);

that, given an array A consisting of N integers and an integer K, returns the array A rotated K times.

For example, given
    A = [3, 8, 9, 7, 6]
    K = 3

the function should return [9, 7, 6, 3, 8]. Three rotations were made:
    [3, 8, 9, 7, 6] -> [6, 3, 8, 9, 7]
    [6, 3, 8, 9, 7] -> [7, 6, 3, 8, 9]
    [7, 6, 3, 8, 9] -> [9, 7, 6, 3, 8]

For another example, given
    A = [0, 0, 0]
    K = 1

the function should return [0, 0, 0]

Given
    A = [1, 2, 3, 4]
    K = 4

the function should return [1, 2, 3, 4]

Assume that:
        N and K are integers within the range [0..100];
        each element of array A is an integer within the range [−1,000..1,000].
 */
using vi_t = vector<int>;

vector<int> solution1(vector<int> &A, int K) {
	vector<int>s(A.begin(),A.end());
	if (s.begin() != s.end())
		for (int i = 0; i < K; i++)
			std::rotate(s.begin(),s.end()-1,s.end());
	return s;
}

vector<int> solution2(vector<int> &A, int K) {
	vector<int>s(A.begin(),A.end());
	if (s.begin() != s.end()) {
		auto num_rotations = K % A.size();
		std::rotate(s.begin(),s.end()-num_rotations,s.end());
	}
	return s;
}

void test_solution(vi_t &A, int K, std::function<vi_t (vi_t &A, int K)> s) {
	auto test_sol = s(A,K);
	long unsigned int output_buffer_len = 256;
	//std::unique_ptr<char> output_buffer = std::make_unique<char>();
    auto output_buffer =
        std::unique_ptr<char, decltype(free)*>{
            reinterpret_cast<char*>(std::malloc(output_buffer_len)),
            std::free };
	//char * output_buffer= (char*)std::malloc(output_buffer_len);
	int status=0;
	char * name = __cxxabiv1::__cxa_demangle(s.target_type().name(), output_buffer.get(), &output_buffer_len, &status);
	std::cout << "signature = " << name << " mangeled = ";
	std::cout << s.target_type().name() << " A =[";
	copy(A.begin(),A.end(),ostream_iterator<int>(cout," "));
	std::cout << "] shifted by K=" << K << " = [";
	copy(test_sol.begin(),test_sol.end(),ostream_iterator<int>(cout," "));
	std::cout << "]" << std::endl;
}

int test() {
	vector<int> A{3, 8, 9, 7, 6};
	test_solution(A, 3, solution1);
	test_solution(A, 3, solution2);
	test_solution(A, 8, solution1);
	test_solution(A, 8, solution2);
	test_solution(A, 5, solution1);
	test_solution(A, 5, solution2);
	test_solution(A, 0, solution1);
	test_solution(A, 0, solution2);

	vector<int> B{8};
	test_solution(B, 10, solution1);
	test_solution(B, 10, solution2);

	vector<int> C{};
	test_solution(C, 3, solution1);
	test_solution(C, 3, solution2);

	return 0;
}
};

namespace OddOccurrencesInArray {
/*
A non-empty array A consisting of N integers is given.
The array contains an odd number of elements, and each element of the array can be paired with
another element that has the same value, except for one element that is left unpaired.

For example, in array A such that:
  A[0] = 9  A[1] = 3  A[2] = 9
  A[3] = 3  A[4] = 9  A[5] = 7
  A[6] = 9

        the elements at indexes 0 and 2 have value 9,
        the elements at indexes 1 and 3 have value 3,
        the elements at indexes 4 and 6 have value 9,
        the element at index 5 has value 7 and is unpaired.

Write a function:

    int solution(vector<int> &A);

that, given an array A consisting of N integers fulfilling the above conditions,
returns the value of the unpaired element.

For example, given array A such that:
  A[0] = 9  A[1] = 3  A[2] = 9
  A[3] = 3  A[4] = 9  A[5] = 7
  A[6] = 9

the function should return 7, as explained in the example above.

Write an efficient algorithm for the following assumptions:

        N is an odd integer within the range [1..1,000,000];
        each element of array A is an integer within the range [1..1,000,000,000];
        all but one of the values in A occur an even number of times.
 */
int solution(vector<int> &A) {
	int sum = 0;
	for (auto e : A) {
		sum ^= e;
	}

	return sum;
}


int test() {
	vector<int> A{1, 3, 5, 9, 1, 3, 5, 7, 9};
	std::cout << "solution of ";
	copy(A.begin(),A.end(),ostream_iterator<int>(cout," "));
	cout << " = " << solution(A);
	std::cout << std::endl;

	return 0;
}
};

// Lesson 3 Time Complexity
namespace FrogJmp {
int solution(int X, int Y, int D) {
	return ((Y - X) / D) + (int)(((Y - X) % D) > 0);
}
int solution2(int X, int Y, int D) {
	return std::ceil((Y - X) /(double)D);
}

int test_frogjmp()
{
	int X=10;
	int Y=85;
	int D=30;
    cout << solution2(X,Y,D) << endl;

	X=0;
	Y=900001;
	D=30;
    cout << solution2(X,Y,D) << endl;

    return 0;
}

int test() {
	std::cout << "solution of " << solution(10, 85, 30) << std::endl;
	std::cout << "solution of " << solution(10, 100, 30) << std::endl;
	std::cout << "solution of " << solution(100, 100, 30) << std::endl;
	std::cout << "solution of " << solution(0, 0, 30) << std::endl;

	std::cout << "solution2 of " << solution2(10, 85, 30) << std::endl;
	std::cout << "solution2 of " << solution2(10, 100, 30) << std::endl;
	std::cout << "solution2 of " << solution2(100, 100, 30) << std::endl;
	std::cout << "solution2 of " << solution2(0, 0, 30) << std::endl;
	std::cout << std::endl;
	return 0;
}
};

namespace PermMissingElem {
/*


 An array A consisting of N different integers is given.
 The array contains integers in the range [1..(N + 1)], which means that exactly one element is missing.

 Your goal is to find that missing element.

 Write a function:

 int solution(vector<int> &A);

 that, given an array A, returns the value of the missing element.

 For example, given array A such that:
 A[0] = 2
 A[1] = 3
 A[2] = 1
 A[3] = 5

 the function should return 4, as it is the missing element.

 Write an efficient algorithm for the following assumptions:

 N is an integer within the range [0..100,000];
 the elements of A are all distinct;
 each element of array A is an integer within the range [1..(N + 1)].
 */
int solution(vector<int> &A) {
	int size = A.size();
	int N = size + 1;
	if (size == 0) {
		return 1;
	}
	sort(A.begin(), A.end());
	if (A[0] == 2) {
		return 1;
	}
	for (int i = 0; i < N; i++) {
		if (A[i] > i+1) {
			return i+1;
		}
	}
	return N;
}

int test() {
	vector<int> A{2,3,1,5};
	std::cout << "solution of PermMissingElem:" << solution(A) << std::endl;
	return 0;
}
}
;

namespace TapeEquilibrium {
/*
 A non-empty zero-indexed array A consisting of N integers is given. Array A represents numbers on a tape.
Any integer P, such that 0 < P < N, splits this tape into two non−empty parts: A[0], A[1], …, A[P − 1] and A[P], A[P + 1], …, A[N − 1].
The difference between the two parts is the value of: |(A[0] + A[1] + … + A[P − 1]) − (A[P] + A[P + 1] + … + A[N − 1])|
In other words, it is the absolute difference between the sum of the first part and the sum of the second part.

Write a function that, given a non-empty zero-indexed array A of N integers, returns the minimal difference that
can be achieved.

Example:
      A[0] = 3
      A[1] = 1
      A[2] = 2
      A[3] = 4
      A[4] = 3
We can split this tape in four places:
P = 1, difference = |3 − 10| = 7
P = 2, difference = |4 − 9| = 5
P = 3, difference = |6 − 7| = 1
P = 4, difference = |10 − 3| = 7
In this case I would return 1 as it is the smallest difference.

N is an int, range [2..100,000]; each element of A is an int, range [−1,000..1,000]. It needs to be O(n)
time complexity,
*/
int solution(vector<int> & A) {
	auto N=A.size();
	vector<long> B(N);

	// Do a running cum count at each point, used as a lookup B
	auto it= A.begin();
	auto last= A.end();
    int value = *it;
    auto result=B.begin();
    *result = value;
    while (++it != last)
	{
	  value = value + *it;
	  *++result = value;
	}

    // P=1
    // Last elemen in running sum is the total
    auto total_sum = B[N-1];
    auto lsum = B[0];
    auto rsum = total_sum - lsum;
    auto diff = std::abs(lsum-rsum);
    auto ret = diff;

    // P=2 .. P=N-1
    for (decltype(N) P=2;P<N;++P) {
    	lsum = B[P-1];
    	rsum = total_sum - lsum;
    	diff = std::abs(lsum-rsum);
    	if (diff<ret) {
    		ret = diff;
    	}
    }

	return ret;
}

int test()
{
    vector<int> A = {3,1,2,4,3};
    std::cout << "A=[3,1,2,4,3]" << std::endl;
    cout << solution(A) << endl;
    A = {-1000, 1000};
    cout << solution(A) << endl;

    return 0;
}
};

// Lesson 4 - Counting Elements

namespace MaxCounters {
/*
 You are given N counters, initially set to 0, and you have two possible operations on them:

        increase(X) − counter X is increased by 1,
        max counter − all counters are set to the maximum value of any counter.

A non-empty array A of M integers is given. This array represents consecutive operations:

        if A[K] = X, such that 1 ≤ X ≤ N, then operation K is increase(X),
        if A[K] = N + 1 then operation K is max counter.

For example, given integer N = 5 and array A such that:
    A[0] = 3
    A[1] = 4
    A[2] = 4
    A[3] = 6
    A[4] = 1
    A[5] = 4
    A[6] = 4

the values of the counters after each consecutive operation will be:
    (0, 0, 1, 0, 0)
    (0, 0, 1, 1, 0)
    (0, 0, 1, 2, 0)
    (2, 2, 2, 2, 2)
    (3, 2, 2, 2, 2)
    (3, 2, 2, 3, 2)
    (3, 2, 2, 4, 2)

The goal is to calculate the value of every counter after all operations.
 */

vector<int> solution(int N, vector<int> &A)
{
    vector<int> result(N,0);
    int M = (int)A.size();
    int max = 0;
    int maxAtTheLastMaxCntOp = 0;

    for (int i = 0; i < M; i++){
        int op = A[i];
        //if the op is max counter.
        if (op == N + 1){
            maxAtTheLastMaxCntOp = max;
        }
        //if the op is increase(x)
        else {
            auto res_indx = op-1;
            if (result[res_indx] < maxAtTheLastMaxCntOp){
                result[res_indx] = maxAtTheLastMaxCntOp + 1;
            }
            else {
                result[res_indx]++;
            }
            //update the max value if necessary.
            if (max < result[res_indx]){
                max = result[res_indx];
            }
        }
    }

    //apply the 'max counter' operation
    //to the slot(s) where it should be applied.
    int j;
    for (j = 0; j < N; j++){
        if (result[j] < maxAtTheLastMaxCntOp){
            result[j] = maxAtTheLastMaxCntOp;
        }
    }
    return result;
}

int test() {
	vector<int> A{3,4,4,6,1,4,4};
	auto sv = solution(5,A);
	std::cout << "MaxCounters test 1=";
	copy(sv.begin(), sv.end(), ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	return 0;
}
};


namespace MissingInteger {

int solution(vector<int> & A)
{
	int N = (int)A.size();
    //prepare the flags
	vector<int> flag(N,0);

    //iterate the given array A.
    for (int i = 0; i < N; i++){
        //we can neglect the value below 1 or larger than N.
        if (A[i] <= 0 || A[i] > N){
            continue;
        }
        //turn on the flag. this is the zero-indexed array.
        //so give -1 as the offset.
        flag[A[i] - 1] = 1;
    }

    //if there is no positive integer lacking between 1 - N,
    //the answer should be N + 1.
    int ans = N + 1;
    //found the minimum integer that is not found in the array A.
    for (int i = 0; i < N; i++){
        if (flag[i] == 0){
            //the answer is (the index + 1). (we have -1 offset).
            ans = i + 1;
            break;
        }
    }

    return ans;
}

int test() {
	vector<int> A1{1, 3, 6, 4, 1, 2};
	std::cout << "MissingInteger solution 1 smallest positive " << solution(A1) << std::endl;
	vector<int> A2{1, 2, 3};
	std::cout << "MissingInteger solution 2 smallest positive " << solution(A2) << std::endl;
	vector<int> A3{-1, -3};
	std::cout << "MissingInteger solution 3 smallest positive " << solution(A3) << std::endl;

	return 0;
}
};

namespace PermCheck {
/*
A non-empty array A consisting of N integers is given.

A permutation is a sequence containing each element from 1 to N once, and only once.

For example, array A such that:
    A[0] = 4
    A[1] = 1
    A[2] = 3
    A[3] = 2

is a permutation, but array A such that:
    A[0] = 4
    A[1] = 1
    A[2] = 3

is not a permutation, because value 2 is missing.

The goal is to check whether array A is a permutation.

Write a function:

    int solution(vector<int> &A);

that, given an array A, returns 1 if array A is a permutation and 0 if it is not.

For example, given array A such that:
    A[0] = 4
    A[1] = 1
    A[2] = 3
    A[3] = 2

the function should return 1.

Given array A such that:
    A[0] = 4
    A[1] = 1
    A[2] = 3

the function should return 0.

Write an efficient algorithm for the following assumptions:

        N is an integer within the range [1..100,000];
        each element of array A is an integer within the range [1..1,000,000,000].


 */
int solution(vector<int> & A)
{
	int N = (int)A.size();
    //prepare the flags
	vector<int> flag(N+1,0);


    for (int i = 0; i < N; i++){
    	if (A[i] > N) {
    		return 0;
    	}
        if (flag[A[i]] > 0) {
        	return 0;
        }
        flag[A[i]]++;
    }

    for (int i = 1; i <= N; i++){
        if (flag[i] == 0){
        	return 0;
        }
    }

    return 1;
}

int test() {
	vector<int> A1{3, 6, 4, 1, 2, 5};
	std::cout << "PermCheck solution 1 " << solution(A1) << std::endl;
	vector<int> A2{1, 2, 3, 3};
	std::cout << "PermCheck solution 2  " << solution(A2) << std::endl;
	vector<int> A3{1, 2, 4, 5, 6, 7};
	std::cout << "PermCheck solution 3  " << solution(A3) << std::endl;
	vector<int> A4{1};
	std::cout << "PermCheck solution 4  " << solution(A4) << std::endl;
	vector<int> A5{100000};
	std::cout << "PermCheck solution 5  " << solution(A5) << std::endl;

	return 0;
}
};


namespace FrogRiverOne {
/*
A small frog wants to get to the other side of a river. The frog is initially located on one bank of the river (position 0) and wants to get to the opposite bank (position X+1).
Leaves fall from a tree onto the surface of the river.

You are given an array A consisting of N integers representing the falling leaves. A[K] represents the position where one leaf falls at time K, measured in seconds.

The goal is to find the earliest time when the frog can jump to the other side of the river.
The frog can cross only when leaves appear at every position across the river from 1 to X (that is,
we want to find the earliest moment when all the positions from 1 to X are covered by leaves). You may assume that the speed of the current in the river is negligibly small, i.e.
 the leaves do not change their positions once they fall in the river.

For example, you are given integer X = 5 and array A such that:
  A[0] = 1
  A[1] = 3
  A[2] = 1
  A[3] = 4
  A[4] = 2
  A[5] = 3
  A[6] = 5
  A[7] = 4

In second 6, a leaf falls into position 5. This is the earliest time when leaves appear in every position across the river.

Write a function:

    int solution(int X, vector<int> &A);

that, given a non-empty array A consisting of N integers and integer X, returns the earliest time when the frog can jump to the other side of the river.

If the frog is never able to jump to the other side of the river, the function should return −1.

For example, given X = 5 and array A such that:
  A[0] = 1
  A[1] = 3
  A[2] = 1
  A[3] = 4
  A[4] = 2
  A[5] = 3
  A[6] = 5
  A[7] = 4

the function should return 6, as explained above.

Write an efficient algorithm for the following assumptions:

        N and X are integers within the range [1..100,000];
        each element of array A is an integer within the range [1..X].
 */
int solution(int X, vector<int> &A) {
	int N = A.size();
	int leaf_count = 0;
	vector<int> fallen(X+1,0);

	for (int i = 0; i < N; i++) {
		if (A[i] <= X and fallen[A[i]] == 0) {
			fallen[A[i]] = 1;
			leaf_count++;
		}
		if (leaf_count == X) {
			return i;
		}
	}
	return -1;
}

int test() {
	vector<int> A1 { 1,3,1,4,2,3,5,4 };
	std::cout << "FrogRiverOne solution 1 " << solution(5,A1) << std::endl;

	return 0;
}
}
;


// Lesson 5 Prefix Sums

namespace PassingCars {
int solution(vector<int> &A) {
	int e = 0;
	int p = 0;
	// So basically if car is going east (a ==0) this is a car that will pass one going west
	// If it is not a== 1 then if there are any cars before this one we recorded going east then
	// it will pass all of these (the prefix sum), if there are not cars then it will pass none
	// and p passing will still be zero untila car going east appears
	for (auto a : A) {
		if (a == 0)
			e++;
		else
			p += e;
	}

	if (p > 1e9 or p < 0) p = -1;
	return p;
}

int test() {
	vector<int> A{0, 1, 0, 1, 1};
	std::cout << "PassingCars solution of " << solution(A) << std::endl;
	return 0;
}
};


namespace GenomicRangeQuery {
/*
 A DNA sequence can be represented as a string consisting of the letters A, C, G and T, which correspond to the
 types of successive nucleotides in the sequence. Each nucleotide has an impact factor, which is an integer.
 Nucleotides of types A, C, G and T have impact factors of 1, 2, 3 and 4, respectively.
 You are going to answer several queries of the form: What is the minimal impact factor of
 nucleotides contained in a particular part of the given DNA sequence?

The DNA sequence is given as a non-empty string S = S[0]S[1]...S[N-1] consisting of N characters.
 There are M queries, which are given in non-empty arrays P and Q, each consisting of M integers.
 The K-th query (0 ≤ K < M) requires you to find the minimal impact factor of nucleotides contained in the DNA sequence between positions P[K] and Q[K] (inclusive).

For example, consider string S = CAGCCTA and arrays P, Q such that:
    P[0] = 2    Q[0] = 4
    P[1] = 5    Q[1] = 5
    P[2] = 0    Q[2] = 6

The answers to these M = 3 queries are as follows:

        The part of the DNA between positions 2 and 4 contains nucleotides G and C (twice), whose impact factors are 3 and 2 respectively, so the answer is 2.
        The part between positions 5 and 5 contains a single nucleotide T, whose impact factor is 4, so the answer is 4.
        The part between positions 0 and 6 (the whole string) contains all nucleotides, in particular nucleotide A whose impact factor is 1, so the answer is 1.

Write a function:

    class Solution { public int[] solution(String S, int[] P, int[] Q); }

that, given a non-empty string S consisting of N characters and two non-empty arrays P and Q consisting of M integers,
returns an array consisting of M integers specifying the consecutive answers to all queries.

Result array should be returned as an array of integers.

For example, given the string S = CAGCCTA and arrays P, Q such that:
    P[0] = 2    Q[0] = 4
    P[1] = 5    Q[1] = 5
    P[2] = 0    Q[2] = 6

the function should return the values [2, 4, 1], as explained above.
 */

typedef struct ACGT {
	int a;
	int c;
	int g;
	int t;
} ACGT;


vector<ACGT> getNucleotides(string &S) {
	// Running count as we move along Genom string
	int N = (int) S.size();
	vector<ACGT> Nucleotides(N + 1);

	int i;
	int a = 0;
	int c = 0;
	int g = 0;
	int t = 0;

	//count the numbers of ACGT.
	for (i = 0; i < N; i++) {
		switch (S[i]) {
		case 'A':
			a++;
			break;
		case 'C':
			c++;
			break;
		case 'G':
			g++;
			break;
		case 'T':
			t++;
			break;
		default:
			exit(-1);
		}

		Nucleotides[i + 1].a = a;
		Nucleotides[i + 1].c = c;
		Nucleotides[i + 1].g = g;
		Nucleotides[i + 1].t = t;
	}

	return Nucleotides;
}

vector<int> solution(string &S, vector<int> &P, vector<int> &Q)
{
	vector<ACGT> Nucleotides = getNucleotides(S);
	int M = (int)P.size();
	vector<int> result(M,0);
    for (int i = 0; i < M; i++){
        ACGT range_start = Nucleotides[P[i]];
        ACGT range_end = Nucleotides[Q[i] + 1];
        if (range_end.a - range_start.a > 0){
            result[i] = 1;
        }
        else if (range_end.c - range_start.c > 0){
            result[i] = 2;
        }
        else if (range_end.g - range_start.g > 0){
            result[i] = 3;
        }
        else {
            result[i] = 4;
        }
    }

    return result;
}

int test() {
	string S = "CAGCCTA";
	vector<int> P{2,5,0};
	vector<int> Q{4,5,6};
	// Quries between P and Q range
	auto sv = solution(S,P,Q);
	std::cout << "GenomicRangeQuery test 1=";
	copy(sv.begin(), sv.end(), ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	return 0;
}
};


namespace MinAvgTwoSlice {
/*
A non-empty array A consisting of N integers is given.

A pair of integers (P, Q), such that 0 ≤ P < Q < N, is called a slice of array
A (notice that the slice contains at least two elements). The average of a slice (P, Q) is the sum of A[P] + A[P + 1] + ... + A[Q]
divided by the length of the slice. To be precise, the average equals (A[P] + A[P + 1] + ... + A[Q]) / (Q − P + 1).

For example, array A such that:
    A[0] = 4
    A[1] = 2
    A[2] = 2
    A[3] = 5
    A[4] = 1
    A[5] = 5
    A[6] = 8

contains the following example slices:

        slice (1, 2), whose average is (2 + 2) / 2 = 2;
        slice (3, 4), whose average is (5 + 1) / 2 = 3;
        slice (1, 4), whose average is (2 + 2 + 5 + 1) / 4 = 2.5.

The goal is to find the starting position of a slice whose average is minimal.

Write a function:

    int solution(vector<int> &A);

that, given a non-empty array A consisting of N integers, returns the starting position of the slice with the minimal average.
If there is more than one slice with a minimal average, you should return the smallest starting position of such a slice.

For example, given array A such that:
    A[0] = 4
    A[1] = 2
    A[2] = 2
    A[3] = 5
    A[4] = 1
    A[5] = 5
    A[6] = 8

the function should return 1, as explained above.

Write an efficient algorithm for the following assumptions:

        N is an integer within the range [2..100,000];
        each element of array A is an integer within the range [−10,000..10,000].

 */

int solution(vector<int> &A) {
	int N = (int)A.size();

	if (N == 2) {
		return 0;
	}

	//initialize the current minimum average of the first two slots.
	double minavg = (A[0] + A[1]) / 2.0;
	int minAvgTwoSliceIdx = 0;

	for (int i = 2; i < N; i++) {
		/*
		 * So if average goes down from previous on 2 elements then it follows this is where
		 * we should start the next time. If it is lower using 3 numbers
		 */
		double tmp1 = (A[i - 1] + A[i]) / 2.0;
		double tmp2 = (A[i - 2] + A[i - 1] + A[i]) / 3.0;

		if (tmp1 < minavg) {
			minAvgTwoSliceIdx = i - 1;
			minavg = tmp1;
		}
		if (tmp2 < minavg) {
			minAvgTwoSliceIdx = i - 2;
			minavg = tmp2;
		}
	}

	return minAvgTwoSliceIdx;
}


int test() {
	vector<int> A1{4,2,2,5,1,5,8};
	std::cout << "MinAvgTwoSlice solution 1 of " << solution(A1) << std::endl;
	vector<int> A2{2,1,1};
	std::cout << "MinAvgTwoSlice solution 2 of " << solution(A2) << std::endl;
	return 0;
}
};

namespace CountDiv {
/*

Write a function:

    int solution(int A, int B, int K);

that, given three integers A, B and K, returns the number of integers within the range [A..B] that are divisible by K, i.e.:

    { i : A ≤ i ≤ B, i mod K = 0 }

For example, for A = 6, B = 11 and K = 2, your function should return 3, because there are three numbers divisible by 2 within the range [6..11], namely 6, 8 and 10.

Write an efficient algorithm for the following assumptions:

        A and B are integers within the range [0..2,000,000,000];
        K is an integer within the range [1..2,000,000,000];
        A ≤ B.

!!NB check range conditions!!!
 */
int solution(int A, int B, int K) {

	int count = 0;
	for (int i = A; i <= B; i++) {
		if (i % K == 0) count++;
	}

	return count;
}

int solution2(int A, int B, int K) {
	if (A==0 and B==0) return 1;
	int count = 0;
	if (A==0) { A++; count++; }
	count += B/K - (A-1)/K;
	return count;
}

int test() {
	std::cout << "CountDiv solution 1 of " << solution2(6,11,2) << std::endl;
	std::cout << "CountDiv solution 1 of " << solution2(0,0,11) << std::endl;
	std::cout << "CountDiv solution 1 of " << solution2(0,22,11) << std::endl;

	return 0;
}

}
//Lesson 6 Sorting

namespace MaxProductOfThree {
int solution(vector<int> &A) {
	// Sorting the vector means
	// we look for the biggest product wee can get
	// If there were only positives then
	// it must be a product of the three biggest positives
	// Zero is not allowed, but if there are negatives
	// these are at the other end of the sort
	// and what we need to do is see if there are 2 negative
	// numbers which multiple together that are bigger than
	// the 2 positives before the biggest
        std::sort(A.begin(),A.end());
        auto s1 = A.front();
        auto s2 = *(A.begin()+1);
        auto b1 = *(A.end()-1);
        auto b2 = *(A.end()-2);
        auto b3 = *(A.end()-3);
        int m = b3*b2*b1;
        if (s1*s2 > b3*b2 and b1 > 0) m = s1*s2*b1;
        return m;
}

int solution2(vector<int> &A) {
	// Exactly the same as previous solution
	// Just does not rely on sort
	// So slightly quicker O(N)
	constexpr const int MAX_P = 1001;
	constexpr const int MIN_P = -1001;

	   if (A.size() == 3){
	        return A[0] * A[1] * A[2];
	    }

	    int max1 = MIN_P;
	    int max2 = MIN_P;
	    int max3 = MIN_P;

	    int min1 = MAX_P;
	    int min2 = MAX_P;

	    for (auto tmp : A) {
	        if (tmp > max1){
	            max3 = max2;
	            max2 = max1;
	            max1 = tmp;
	        }
	        else if (tmp > max2){
	            max3 = max2;
	            max2 = tmp;
	        }
	        else if (tmp > max3){
	            max3 = tmp;
	        }

	        if (tmp < min1){
	            min2 = min1;
	            min1 = tmp;
	        }
	        else if (tmp < min2){
	            min2 = tmp;
	        }
	    }

	    int val1 = max1 * max2 * max3;
	    int val2 = max1 * min1 * min2;

	    return val1 > val2 ? val1 : val2;
}

// Driver program to test above function
int test() {
    vector<int> A{-3, 1, 2, -2, 5, 6};
    std::cout << "MaxProductOfThree solution of " << solution(A) << std::endl;
    vector<int> B{-5, -6, -4, -7, -10};
    std::cout << "MaxProductOfThree solution of " << solution(B) << std::endl;
	return 0;
}

};

namespace Distinct {
/*
	int solution(vector<int> &A);

that, given an array A consisting of N integers, returns the number of distinct values in array A.

For example, given array A consisting of six elements such that:
 A[0] = 2    A[1] = 1    A[2] = 1
 A[3] = 2    A[4] = 3    A[5] = 1

the function should return 3, because there are 3 distinct values appearing in array A, namely 1, 2 and 3.

Write an efficient algorithm for the following assumptions:

        N is an integer within the range [0..100,000];
        each element of array A is an integer within the range [−1,000,000..1,000,000].
*/

int solution(vector<int> &A) {
	std::sort(A.begin(), A.end());
	auto last = std::unique(A.begin(), A.end());
	return std::distance(A.begin(), last);
}

// Driver program to test above function
int test() {
    vector<int> A{2, 1, 1, 2, 3, 1};
    std::cout << "Distinct solution of " << solution(A) << std::endl;

	return 0;
}

};

namespace Triangle {
/*

An array A consisting of N integers is given. A triplet (P, Q, R) is triangular if 0 ≤ P < Q < R < N and:

        A[P] + A[Q] > A[R],
        A[Q] + A[R] > A[P],
        A[R] + A[P] > A[Q].

For example, consider array A such that:
  A[0] = 10    A[1] = 2    A[2] = 5
  A[3] = 1     A[4] = 8    A[5] = 20

Triplet (0, 2, 4) is triangular.

Write a function:

    int solution(vector<int> &A);

that, given an array A consisting of N integers, returns 1 if there exists a triangular
triplet for this array and returns 0 otherwise.

For example, given array A such that:
  A[0] = 10    A[1] = 2    A[2] = 5
  A[3] = 1     A[4] = 8    A[5] = 20

the function should return 1, as explained above. Given array A such that:
  A[0] = 10    A[1] = 50    A[2] = 5
  A[3] = 1

the function should return 0.

Write an efficient algorithm for the following assumptions:

        N is an integer within the range [0..100,000];
        each element of array A is an integer within the range [−2,147,483,648..2,147,483,647].


*/

int solution(vector<int> &A) {
	std::sort(A.begin(), A.end());

    int i;
    for (i = 2; i < (int)A.size(); i++){
    	// A[P] + A[Q] > A[R]
        int p = A[i - 2];
        int q = A[i - 1];
        int r = A[i];

        if (p <= 0 or q <=0 or r <=0){
            continue;
        }

        if (r - p < q ){
            return 1;
        }
    }

    return 0;
}

// Driver program to test above function
int test() {
	vector<int> A1{10,2,5,1,8,20};
    std::cout << "Triangle solution of 1 is " << solution(A1) << std::endl;
    vector<int> A2{10, 50,  5, 1};
    std::cout << "Triangle solution of 2 is " << solution(A2) << std::endl;

	return 0;
}

};

namespace NumberOfDiscIntersections {

/*
We draw N discs on a plane.
The discs are numbered from 0 to N − 1. An array A of N non-negative integers,
specifying the radiuses of the discs, is given.
The J-th disc is drawn with its center at (J, 0) and radius A[J].

We say that the J-th disc and K-th disc intersect
if J ≠ K and the J-th and K-th discs have at least
one common point (assuming that the discs contain their borders).

The figure below shows discs drawn for N = 6 and A as follows:
  A[0] = 1
  A[1] = 5
  A[2] = 2
  A[3] = 1
  A[4] = 4
  A[5] = 0

There are eleven (unordered) pairs of discs that intersect, namely:

        discs 1 and 4 intersect, and both intersect with all the other discs;
        disc 2 also intersects with discs 0 and 3.

Write a function:

    int solution(vector<int> &A);

that, given an array A describing N discs as explained above, returns the number of (unordered) pairs of intersecting discs. The function should return −1 if the number of intersecting pairs exceeds 10,000,000.

Given array A shown above, the function should return 11, as explained above.

Write an efficient algorithm for the following assumptions:

        N is an integer within the range [0..100,000];
        each element of array A is an integer within the range [0..2,147,483,647].

*/

int solution(vector<int> &A) {
	/*
	struct start_end_t {
		int start;
		int end;
		bool operator<(const start_end_t& c) {
			if (this->start < c.start)
				return true;
			else if (this->start == c.start and this->end < c.end)
				return true;
			else
				return false;
		}
	} ;
*/

	vector<long> start(A.size(),0);
	vector<long> end(A.size(),0);

	for (long d=0;d < (int)A.size(); d++) {
		start[d] = d - A[d];
		end[d] = d + A[d];
	}

	sort(start.begin(),start.end());
	sort(end.begin(),end.end());
	int openr = 0;
	long intersections = 0;
	int j = 0;
	int i = 0;
	while (i < (int)start.size()) {
		if (start[i] <= end[j]) {
			intersections += openr;
			openr++;
			i++;
		}
		else {
			openr--;
			j++;
		}
	}

	if (intersections > 10000000) intersections = -1;
	return intersections;
}

int test() {
	std::vector<int> A1{1, 5, 2, 1, 4, 0};
	cout << "NumberOfDiscIntersections 1:" << solution(A1) << endl;
	std::vector<int> A2{1, 2147483647, 0};
	cout << "NumberOfDiscIntersections 2:" << solution(A2) << endl;
	return 0;
}
}

//Lesson 7 Stacks and Queues

namespace Brackets {

int solution2(char *S) {

    int len = strlen(S);

    if (len == 0){
        return 1;
    }

    //I always wonder why thye don't tell anything about
    //what we shoud do when memory allocation failed
    //in codility problems...
    char*   stack = (char*)alloca(len);


    int idx = 0;  //this is a stack pointer.

    int i;
    //scan the character one-by-one
    for (i = 0; i < len; i++){
        char c = S[i];

        switch(c){
            //if the character is '(', '[', '{',
            //just push it onto the stack.
            case '(':
            case '[':
            case '{':
                stack[idx] = c;
                idx++;
                break;

            //if the character is '(', '[', '{',
            //check if the last character matches with each
            case ')':
                idx--;
                if (stack[idx] != '('){
                    return 0;
                }
                break;
            case ']':
                idx--;
                if (stack[idx] != '['){
                    return 0;
                }
                break;
            case '}':
                idx--;
                if (stack[idx] != '{'){
                    return 0;
                }
                break;
            default:
                return 0;
        }
    }

    //we need to see if the string is terminted collectly
    if (idx != 0){
        return 0;
    }

    return 1;
}

template <typename Compare, typename LastChar>
bool is_in(Compare c, LastChar last) {
	return c == last;
}

template <typename Compare, typename Next, typename ...Rest>
bool is_in(Compare c, Next next, Rest... rest) {
	if (c == next) return true;
	else return is_in(c, rest...);
}

char closing_bracket(char c) {
	switch (c) {
	default:
		return ' ';
	case '{':
		return '}';
	case '[':
		return ']';
	case '(':
		return ')';
	}
}

// Complete the isBalanced function below.

int solution(string &S)
{
	std::stack<char> bs;
	for (auto c : S) {
		if (is_in(c, '{', '[', '(')) {
			bs.push(c);
		} else {
			if (not bs.empty()) {
				if (c == closing_bracket(bs.top()))
					bs.pop();
				else {
					return 0;
				}
			} else {
				return 0;
			}
		}
	}

	return (bs.empty()) ? 1 : 0;
}

int test() {
	std::vector<std::string> test_strings{"{[()]}","{[(])}","{{[[(())]]}}","{}}","{{[[]}}}", "[[]]]", "{{}"};

	for (auto test_string : test_strings) {
		std::cout << "Balanced:" << Brackets::solution(test_string) << std::endl;
	}

	return 0;
}
};

namespace Fish {

/*
 The simplest solution for this problem is to use the stack.
We prepare a stack only for those fish going downstream.

The arrays of the fish size/direction are scanned from the beginning to the end.

If the fish at the current scanning position is going downstream, we put it onto the stack.

When the fish at the current position is going upstream, it starts eating up the fish going downstream from the stack.
If it mets a bigger fish than itself, it dies then. If there is no more fish on the stack,
it means it can reach the upper end of the river. This means it survives. We count up the surviver counter.

The total number of the survived fish is the survivors (heading upstream) and those on the stack
(heading downstream).
 */

int solution(vector<int> &A, vector<int> &B)
{
	int N = (int) A.size();
	std::stack<int> down;

	//the counter for the fish that reached to the end of the river.
	int cnt_reached = 0;

	int i;
	for (i = 0; i < N; i++) {
		//if the fish is going upstream,
		//check if it can reach the upper end.
		if (B[i] == 0) {
			while (1) {
				//if there is no more fish against it,
				//it reaches the upper end.
				if (down.empty()) {
					cnt_reached++;
					break;
				}
				//met a bigger one, they it is eaten..

				if (down.top() > A[i]) {
					break;
				}
				//we keep on eating the fish...
				down.pop();
			}
			continue;
		}
		//the fish is going downstream. push it to the stack.
		down.push(A[i]);
	}

	return down.size() + cnt_reached;
}

int test() {
	std::vector<int> A{4, 3, 2, 1, 5};
	std::vector<int> B{0, 1, 0, 0, 0};

	std::cout << "Fish=" << solution(A,B) << std::endl;

	return 0;
}

};

namespace Nesting {
int solution(string &S)
{
    int lnum = 0;
    int rnum = 0;

    //the string can be empty. no need to scan.
    if (S.size() == 0){
        return 1;
    }

    for (auto p : S){
        if (p == '('){
            lnum++;
        }
        else {
            //the number of ')' can never exceed the number of '('
            rnum++;
            if (rnum > lnum){
                return 0;
            }
        }
    }

    return lnum == rnum;
}

int test() {
	std::vector<std::string> test_strings{"(()(())())","(()(())()",};

	for (auto test_string : test_strings) {
		std::cout << "Nesting:" << Nesting::solution(test_string) << std::endl;
	}

	return 0;
}

};

namespace StoneWall {
int solution(vector<int> &H) {
	int N = (int) H.size();

	int *stack = (int*) alloca(sizeof(int) * N);
	int sp = 0;

	int cnt = 0;

	int i;
	for (i = 0; i < N; i++) {

		//if there is no stone on the left, we need a new stone.
		if (sp == 0) {
			cnt++;
			stack[sp++] = H[i];
			//check the next height.
			continue;
		}

		//there is at least one stone on the left

		//the same hight, we don't need a new stone.
		if (stack[sp - 1] == H[i]) {
			//check the next height.
			continue;
		}

		//the hight goes up, we need a new stone
		if (stack[sp - 1] < H[i]) {
			cnt++;
			stack[sp++] = H[i];
			//check the next height.
			continue;
		}

		//the hight goes down, try rewinding the stack
		while (1) {

			//the stone on the left is still heigher.
			//try rewind the stack.
			if (stack[sp - 1] > H[i]) {
				sp--;

				//reached the bottom of the stack.
				if (sp == 0) {
					//we need a new stone.
					cnt++;
					stack[sp++] = H[i];
					break;
				}
				continue;
			}

			//there is a stone with the same height on the left.
			//this can continue grow to the right.
			if (stack[sp - 1] == H[i]) {
				break;
			}

			//the stone on the left is lower than the new height.
			//there is need for a new stone.
			stack[sp++] = H[i];
			cnt++;
			break;
		}

	}

	return cnt;
}

int solution2(std::vector<int> & H) {
    int block_cnt = 0;
    std::stack<int> s;
    for (auto height : H) {
        // remove all blocks that are bigger than my height
        while (not s.empty() and s.top() > height)
            s.pop();

        if (not s.empty() and  s.top() == height) {
            // we already paid for this size
            continue;
        }
        else {
            // new block is required, push it's size to the stack
            block_cnt += 1;
            s.push(height);
        }
    }
    return block_cnt;
}

// Driver program to test above function
int test() {
	std::vector<int> H { 8, 8, 5, 7, 9, 8, 7, 4, 8 };
	auto block_cnt = solution(H);
	std::cout << "StoneWall 1 = " << block_cnt << endl;
	block_cnt = solution2(H);
	std::cout << "StoneWall 2 = " << block_cnt << endl;
	return 0;
}

};

// Lesson 8 - Leader

namespace Leader {
/*
This solution also utilizes the O(N) algorithm to find a leader described in
the reading material that Codility provides. First read it briefly.
Open reading material (PDF)

Indeed, the definition of 'dominator' in this problem is the same as
'leader'. So we can use the same algorithm as the previous problem of `equi leader'
*/

/*
int goldenLeader(std::vector<int> &A) {
	int N = (int)A.size();
	int size = 0;
	for (int k = 0;k < N; k++) {
		if(size == 0):
			size += 1;
			value = A[k]
		else:
			if(value != A[k]):
				size -= 1
			else:size += 1
	}
	candidate = -1
	if(size > 0):
		candidate = value
	leader = -1
	count = 0
	for k in xrange(n):
		if(A[k] == candidate):
			count += 1
	if(count > (n >> 1)):
		leader = candidate
	returnleader
}
*/


int solution(std::vector<int> &A) {

    //first find the leader and count its occurances.
    //as all the values on the stack will be the same,
    //we only have to keep one value.
	int N = (int)A.size();
    int sp = 0;
    int candidate = 0;

    int i;
    for (i = 0; i < N; i++){
        if (sp == 0){
            sp++;
            candidate = A[i];
            continue;
        }

        if (candidate == A[i]){
            sp++;
        }
        else {
            sp--;
        }
    }

    //if there is no dominator, return -1
    if (sp == 0){
        return -1;
    }

    //now we check if the candidate value is really a dominator
    int cnt = 0;
    for (i = 0; i < N; i++){
        if (A[i] == candidate){
            cnt++;
        }
    }

    //if there is no dominator, return -1.
    if (cnt <= N / 2){
        return -1;
    }

    //now we have a leader.
    int dominator = candidate;


    //let's find the first dominator in the array
    for (i = 0; i < N; i++){
        if (A[i] == dominator){
            return i;
        }
    }

    //the code won't reach here since we have a dominator.
    return -1;
}

int test() {
	std::vector<int> A1{23171,21011,21123,21366,21013,21367};
	std::cout << "Leader{23171,21011,21123,21366,21013,21367}=" << solution(A1) << std::endl;
	std::vector<int> A2{8, 9, 3, 6, 1, 2};
	std::cout << "Leader{8, 9, 3, 6, 1, 2}=" << solution(A2) << std::endl;
	return 0;
}
};


namespace Dominator {
/*
An array A consisting of N integers is given. The dominator of array A is the value that occurs in more than half of the elements of A.

For example, consider array A such that
 A[0] = 3    A[1] = 4    A[2] =  3
 A[3] = 2    A[4] = 3    A[5] = -1
 A[6] = 3    A[7] = 3

The dominator of A is 3 because it occurs in 5 out of 8 elements of A (namely in those with indices 0, 2, 4, 6 and 7) and 5 is more than a half of 8.

Write a function

    int solution(vector<int> &A);

that, given an array A consisting of N integers, returns index of any element of array A in which the dominator of A occurs. The function should return −1 if array A does not have a dominator.

For example, given array A such that
 A[0] = 3    A[1] = 4    A[2] =  3
 A[3] = 2    A[4] = 3    A[5] = -1
 A[6] = 3    A[7] = 3

the function may return 0, 2, 4, 6 or 7, as explained above.

Write an efficient algorithm for the following assumptions:

        N is an integer within the range [0..100,000];
        each element of array A is an integer within the range [−2,147,483,648..2,147,483,647].

 */
int solution1(vector<int> &A) {
	int N = (int) A.size();
    //first find the leader and count its occurances.
    //as all the values on the stack will be the same,
    //we only have to keep one value.
    int sp = 0;
    int candidate = 0;

    int i;
    for (i = 0; i < N; i++){
        if (sp == 0){
            sp++;
            candidate = A[i];
            continue;
        }

        if (candidate == A[i]){
            sp++;
        }
        else {
            sp--;
        }
    }

    //if there is no dominator, return -1
    if (sp == 0){
        return -1;
    }

    //now we check if the candidate value is really a dominator
    int cnt = 0;
    for (i = 0; i < N; i++){
        if (A[i] == candidate){
            cnt++;
        }
    }

    //if there is no dominator, return -1.
    if (cnt <= N / 2){
        return -1;
    }

    //now we have a leader.
    int dominator = candidate;


    //let's find the first dominator in the array
    for (i = 0; i < N; i++){
        if (A[i] == dominator){
            return i;
        }
    }

    //the code won't reach here since we have a dominator.
    return -1;
}

int solution(vector<int> &A) {
	if (A.size() == 0)
		return -1;
	std::unordered_map<int,int> counter;
	auto biggest_count = 0;
	auto biggest_count_index = -1;
	for (decltype(A.size()) index = 0; index < A.size(); index++) {

		auto value = A[index];
		if (counter.find(value)==counter.end())
			counter[value] = 1;
		else
			counter[value] += 1;

		if (counter[value] > biggest_count) {
			biggest_count = counter[value];
			biggest_count_index = index;
		}
		else if (counter[value] == biggest_count) {
			biggest_count_index = -1;
		}
	}

	if ((int)A.size() - biggest_count >= biggest_count)
		biggest_count_index = -1;

	return biggest_count_index;
}

int test() {
	std::vector<int> A{3, 4, 3, 2, 3, -1, 3, 3};
	std::cout << "Dominator{3, 4, 3, 2, 3, -1, 3,3}=" << solution(A) << std::endl;
	 std::random_device rd; // seed
	 std::mt19937 gen(rd()); // generator
	 std::uniform_int_distribution<> dis(-1000,1000);
	 std::vector<int> v;
	 std::generate_n(std::back_inserter(v),100000,[&](){return dis(gen);});
	 std::cout << "Dominator=" << solution(v) << std::endl;
	 std::vector<int> A2{1, 2, 3, 4, 5};
	 std::cout << "Dominator{1, 2, 3, 4, 5}=" << solution(A2) << std::endl;
	 std::vector<int> A3{2147483647};
	 std::cout << "Dominator{2147483647}=" << solution(A3) << std::endl;
	 std::vector<int> A4{2,2,2,2,2,3,3,3,3,3,3};
	 std::cout << "Dominator{2,2,2,2,2,3,3,3,3,3,3}=" << solution(A4) << std::endl;
	 std::vector<int> A5{2,2,2,2,2,3,3,3,3,3};
	 std::cout << "Dominator{2,2,2,2,2,3,3,3,3,3}=" << solution(A5) << std::endl;
	 std::vector<int> A6{2,2,2,2,2,3,3,3,3,3,3,4};
	 std::cout << "Dominator{2,2,2,2,2,3,3,3,3,3,4}=" << solution(A6) << std::endl;

	 return 0;
}

};

namespace EquiLeader {
/*
 As my solution utilizes the O(N) algorithm to find a leader described in the reading material that
 Codility provides, so first read it briefly.
Open reading material (PDF)


The definition of `equi leader' is given as below in the problem.


``An equi leader is an index S such that 0 ≤ S < N − 1 and two sequences
A[0], A[1], ..., A[S] and A[S + 1], A[S + 2], ..., A[N − 1] have leaders of the same value.''

So let's think of this.

Assume the value X is the leader of the whole array A and the total number of its occurrence is cntX.

Now we have the value Y and the total number of its occurrence is cntY. The value Y can be any value other than X.

Since X is the leader, it can be said that cntX > N / 2.

Then, it is always cntY < N / 2, since cntX + cntY <= N (because cntX > N / 2)

Since cntX > N / 2 and N / 2 > cntY, we can say cntX > cntY


The question is if this value Y can have an equi leader. The answer is NO, which means
``The leaders of the same value that makes an equip leader is always the leader of the whole array''.

Why? Assume that the value Y can have an equi leader at the index S.
This means, for A[0], A[1], ...., A[S], Y occurs more than X.

Suppose the number of occurrences of X and Y on the left side of the array divided by the index
S are cntX_L, cntY_L respectively.

Then for A[n] (n <= S),
it must be cntY_L > cntX_L  as Y is supposed to occur more than X to become the leader on the left
side of the array divided at the index S.

Now let's think if Y can be also a leader of the right side of the array divided by the index S.

The total number of the occurrences of X and Y on the right side is cntX - cntX_L and cntY - cntY_L respectively.

so if the Y can also become the leader of the right side, it has to be cntX - cntX_L < cntY - cntY_L.

However, the assumption above leads to a contradiction.

cntX - cntX_L < cntY - cntY_L

This obviously contradicts since we assumed

cntX   > cntY
cntX_L < cntY_L

This can only result as below.

cntX - cntX_L > cntY - cntY_L


This means that only the leader of the whole array can have an equi leader.


Based on this condition, to solve this problem, we first find the leader of the whole array.
If there is no leader, there won't be no equal leader. So just return 0.

After finding a leader (if any), we then scan the whole array again,
counting the occurrence of the leader at the current scanning position, comparing if the position can be an equi leader or not.
If we find a new equi leader, we increment the counter for the answer.
 */
int solution(std::vector<int> &A)
{
    //first find the leader and count its occurrences.
    //as all the values on the stack will be the same,
    //we only have to keep one value.
	int N = (int) A.size();
    int sp = 0;
    int candidate = 0;

    int i;
    for (i = 0; i < N; i++){
        if (sp == 0){
            sp++;
            candidate = A[i];
            continue;
        }

        if (candidate == A[i]){
            sp++;
        }
        else {
            sp--;
        }
    }

    //if there is no leader, there is no equi leader.
    if (sp == 0){
        return 0;
    }

    //now we check if the candidate value is really a leader
    int cnt = 0;
    for (i = 0; i < N; i++){
        if (A[i] == candidate){
            cnt++;
        }
    }

    //if there is no leader, there is no equi leader.
    if (cnt <= N / 2){
        return 0;
    }

    //now we have a leader.
    int leader = candidate;


    //let's count the number of equi leader.
    int lcnt = 0; //leader appeard until the index.
    int ans  = 0; //the number of equi leaders.
    for (i = 0; i < N; i++){
        if (A[i] == leader){
            lcnt++;
        }
        //check if the current index is a equi leader
        int lelems = i + 1;
        if ((lcnt > lelems / 2) &&
            ((cnt - lcnt) > (N - lelems) / 2)){
            ans++;
        }
    }

    return ans;
}

int test() {
	std::vector<int> A{4, 3, 4, 4, 4, 2};
	std::cout << "EquiLeader{4, 3, 4, 4, 4, 2}=" << solution(A) << std::endl;
	return 0;
}
};


// Lesson 9 - Maximum slice problem

namespace max_slice {
int golden_max_slice(std::vector<int> &A) {
	int max_ending,max_slice = 0;
	for (auto a : A) {
		std::cout << "max_ending[" << std::max(0, max_ending + a) << "] = " << "std::max(0, max_ending[" << max_ending << "] + a[" << a << "])" << std::endl;
		max_ending = std::max(0, max_ending + a);
		std::cout << "max_slice[" << std::max(max_slice, max_ending) << "] = std::max(max_slice[" << max_slice << "] max_ending[" << max_ending << "] )" << std::endl;
		max_slice = std::max(max_slice, max_ending);
	}
	return max_slice;
}

int test() {
	std::vector<int> A1{5,-7,3,5,-2,4,-1};
	std::cout << "golden_max_slice{{5,-7,3,5,-2,4,-1}=" << golden_max_slice(A1) << std::endl;
return 0;
}

};

namespace MaxProfit {

// Its not maximum slice!!!!!!!!!!!!!!!!!

// Its basically the diff between the min and max which are the start and end of a slice
// Simple really, start with the lowest and if you get a price between this start minimum that is
// bigger than currently recored maximum, then this is the new maximum

int maxProfit(std::vector<int> & prices)
{
	int N = (int)prices.size();
    int max_profit = 0;
    int min_price = prices[0];
    int max_price = min_price;

    for(int i = 1; i < N; i++)
    {
        if(prices[i] < min_price)
        {
        	// reset to this price as it is the smallest seen so far
        	// maybe there is a price further on than make this give a greater
        	// profit than before
        	min_price = max_price = prices[i];
        }
        else if(prices[i] > max_price)
        {
        	max_price = prices[i];
        }
        auto profit = max_price-min_price;
        if(max_profit < profit)
            max_profit = profit;
    }
    return max_profit;
}

int test() {
	std::vector<int> A1{23171,21011,21123,21366,21013,21367};
	std::cout << "MaxProfit{23171,21011,21123,21366,21013,21367}=" << maxProfit(A1) << std::endl;
	std::vector<int> A2{8, 9, 3, 6, 1, 2};
	std::cout << "MaxProfit{8, 9, 3, 6, 1, 2}=" << maxProfit(A2) << std::endl;
	return 0;
}

};

namespace  MaxSliceSum {
/*
 This is another max slice problem.

The difference from the original cordiality reading material Open reading material (PDF) is that the slice can not be empty.

So if the max value of the slice that can end at the current position is smaller than the value at the current position,
we take the later. (note that in the original version in the open reading material uses '0' instead, as the slice can be empty).
 */
int solution(std::vector<int> &A)
{
	int N = (int)A.size();
    int max_ending = A[0];
    int max_slice  = A[0];

    int i;

    for (i = 1; i < N; i++){
        int tmp = max_ending + A[i];
        if (tmp > A[i]) {
           	cout << "max_ending(" << max_ending << ") plus the new element A[" << i << "] = " <<  A[i] << ", is still bigger than the element on its own tmp = max_ending + A[i] (" << tmp << ") so the max slice can still include it" << endl;
        	max_ending = tmp;
        }
        else {
        	cout << "New max ending is A[" << i << "] = " <<  A[i] << " as the A[" << i << "] on its own is bigger on its own than adding to the previous max_ending(" << max_ending << "), which I guess is negative" << endl;
        	max_ending = A[i];
        }

        if (max_slice < max_ending) {
        	cout << "max_slice(" << max_slice << ") is now less than max_ending(" << max_ending << ") so make max_slice = to max_ending(" << max_ending << ")" << endl;
        	max_slice  = max_ending;
        }
        else {
        	cout << "Leave max_slice as is:" << max_slice << endl;
        }
    }

    return max_slice;
}

int test() {
	std::vector<int> A1{3, -6, 4, 0};
	std::cout << "MaxSliceSum{3, -6, 4, 0} 1 = " << solution(A1) << std::endl;
	std::vector<int> A2{5,-7,3,5,-2,4,-1};
	std::cout << "MaxSliceSum{5,-7,3,5,-2,4,-1} 2 = " << solution(A2) << std::endl;
	std::vector<int> A3{2,3,4,5,6,-1,6,2,3,4,5};
	std::cout << "MaxSliceSum{2,3,4,5,6,-1,6,2,3,4,5} 3 = " << solution(A3) << std::endl;
	return 0;
}
};

namespace  MaxDoubleSliceSum {
/*
 *

A non-empty array A consisting of N integers is given.

A triplet (X, Y, Z), such that 0 ≤ X < Y < Z < N, is called a double slice.

The sum of double slice (X, Y, Z) is the total of A[X + 1] + A[X + 2] + ... + A[Y − 1] + A[Y + 1] + A[Y + 2] + ... + A[Z − 1].

For example, array A such that:
    A[0] = 3
    A[1] = 2
    A[2] = 6
    A[3] = -1
    A[4] = 4
    A[5] = 5
    A[6] = -1
    A[7] = 2

contains the following example double slices:

        double slice (0, 3, 6), sum is 2 + 6 + 4 + 5 = 17,
        double slice (0, 3, 7), sum is 2 + 6 + 4 + 5 − 1 = 16,
        double slice (3, 4, 5), sum is 0.

The goal is to find the maximal sum of any double slice.

Write a function:

    int solution(vector<int> &A);

that, given a non-empty array A consisting of N integers, returns the maximal sum of any double slice.

For example, given:
    A[0] = 3
    A[1] = 2
    A[2] = 6
    A[3] = -1
    A[4] = 4
    A[5] = 5
    A[6] = -1
    A[7] = 2

the function should return 17, because no double slice of array A has a sum of greater than 17.

Write an efficient algorithm for the following assumptions:

        N is an integer within the range [3..100,000];
        each element of array A is an integer within the range [−10,000..10,000].


This is yet another max slice problem.
The trick is to compute the maximum ending at each index for the left-side slice and the right-side slice first.
Then, we move Y from 1 to N -2, scanning the max values for the left-side slice and the right-side slice at the index.
 */
int solution(std::vector<int> &A)
{
	int N = (int) A.size();
	if (N <= 3) {
		return 0;
	}

	std::vector<int> max_ending_l(N,0);
	std::vector<int> max_ending_r(N,0);

	int i;

	//the max ending at the index from the left.
	max_ending_l[0] = 0;
	for (i = 1; i < N - 1; i++) {
		int tmp = max_ending_l[i - 1] + A[i];
		max_ending_l[i] = tmp < 0 ? 0 : tmp;
	}

	//the max ending at the index from the right.
	max_ending_r[N - 1] = 0;
	for (i = N - 2; i > 0; i--) {
		int tmp = max_ending_r[i + 1] + A[i];
		max_ending_r[i] = tmp < 0 ? 0 : tmp;
	}

	//then move Y to find the maximum double slice sum
	int max = 0;
	for (i = 1; i < N - 1; i++) {
		int tmp = max_ending_l[i - 1] + max_ending_r[i + 1];
		if (max < tmp) {
			max = tmp;
		}
	}

	return max;
}

int test() {
	std::vector<int> A{ 3, 2, 6, -1, 4, 5, -1, 2};
	std::cout << "MaxDoubleSliceSum{3, 2, 6, -1, 4, 5, -1, 2}=" << solution(A) << std::endl;
	return 0;
}
};

// Lesson 10 - Prime and composite numbers

namespace Divisors {

int divisors(int n) {
	int num_divisors = 0;
	int a = 1;
	for (; a*a < n; a++) {
		if (n % a  == 0) {
			// Must have 2 results a * b = n
			// If is one and divides b must be
			// other number
			// Also a and b must be divisors of n * n
			num_divisors += 2;
		}
	}
	if (a * a == n) {
		// Last one
		num_divisors += 1;
	}

	return num_divisors;
}

bool primality(int n) {
	return divisors(n) == 2;
}

bool primality2(int n) {
	int a = 2;
	for (; a*a <= n; a++) {
		if (n % a  == 0) {
			return false;
		}
	}

	return true;
}

// Driver program to test above function
int test() {
	std::cout << "Number of divisors (including 1 and itself) for " << 64
			<< " is " << divisors(64) << std::endl;
	std::cout << "Number of divisors (including 1 and itself) for " << 24
			<< " is " << divisors(24) << std::endl;
	std::cout << "Number of divisors (including 1 and itself) for " << 23
			<< " is " << divisors(23) << std::endl;

	std::cout << std::boolalpha << 1123
			<< " as prime is " << primality(1123) << std::endl;
	std::cout << std::boolalpha << 1123
			<< " as prime is " << primality2(1123) << std::endl;
	return 0;
}

}
;

namespace CountFactors {

int solution(int N) {
	int num_factors = 0;
	int a = 1;
	auto max_a = (int)std::sqrt(INT_MAX);
	for (; a <= max_a and a * a < N; a++) {
		if (N % a == 0) {
			// Must have 2 results a * b = n
			// If is one and divides b must be
			// other number
			// Also a and b must be factors of n * n
			num_factors += 2;
		}
	}
	if (a * a == N) {
		// Last one
		num_factors += 1;
	}

	return num_factors;
}

// Driver program to test above function
int test() {
	std::cout << "Number of factors (including 1 and itself) for " << 64
			<< " is " << solution(64) << std::endl;
	std::cout << "Number of factors (including 1 and itself) for " << 24
			<< " is " << solution(24) << std::endl;
	std::cout << "Number of factors (including 1 and itself) for " << 23
			<< " is " << solution(23) << std::endl;

	using Clock = std::chrono::steady_clock;
	auto start = Clock::now();
	auto s1 = solution(INT_MAX);
	std::cerr << std::chrono::duration_cast<std::chrono::milliseconds>(Clock::now() - start).count() << std::endl;

	std::cout << "Number of factors (including 1 and itself) for " << INT_MAX
			<< " is " << s1 << std::endl;

	return 0;
}

}
;

namespace SieveOfEratosthenes {
int get_sieve(int n, vector<bool> & sieve) {
	sieve[0] = false;
	sieve[1] = false;
	int non_prime_count = 1;
	int i = 2;

	while (i * i <= n) {
		if (sieve[i]) {
			int k = i * i;
			while (k <= n) {
				if (sieve[k]) {
					sieve[k] = false;
					non_prime_count++;
				}
				k += i;
			}
		}
		i += 1;
	}

	return n - non_prime_count;
}

vector<int> get_factors(int n) {
    vector<int> F(n+1,0);
    int i=2;
    while (i * i <= n) {
        if (F[i] == 0) {
            int k= i * i;
            while (k <= n) {
                if (F[k] == 0) {
                    F[k] = i;
                }
                k += i;
            }
        }
        i += 1;
    }

    return F;
}

vector<int> factorization(int x, vector<int> & F) {
	vector<int> primeFactors;
	while (F[x] > 0) {
        primeFactors.push_back(F[x]);
        x /= F[x];
    }
    primeFactors.push_back(x);
    return primeFactors;
}

bool is_semi_prime(int x, vector<int> & F) {
    int smallest_prime_factor = F[x];
    if (smallest_prime_factor > 0) {
        int quotient = x / smallest_prime_factor;
        return F[quotient] == 0;
    }
    return false;
}

vector<int>  get_semiprimes(int n) {
   vector<int> F = get_factors(n);
   vector<int> S;
    int i=2;
    while (i <= n) {
        if (is_semi_prime(i, F)) {
            S.push_back(i);
        }
        i += 1;
    }

    return S;
}


// Driver program to test above function
int test1() {
	std::cout << "get_sieve 1 = ";
	int n = 66;
	vector<bool> sieve(n + 1,true);
	auto prime_count = get_sieve(n,sieve);
	vector<int> primes(prime_count,0);
	for (int i = 2, j = 0; i < n + 1; i++) {
		if (sieve[i]) {
			primes[j++] = i;
		}
	}
	copy(primes.begin(),primes.end(),ostream_iterator<int>(cout," "));
	cout << std::endl;
	return 0;
}



// Driver program to test above function
int test() {
	vector<int> semiprimes = get_semiprimes(66);
	copy(semiprimes.begin(),semiprimes.end(),ostream_iterator<int>(cout,", "));
	cout << std::endl;
	return 0;
}

}

namespace CountSemiprimes {
/*
A prime is a positive integer X that has exactly two distinct divisors: 1 and X. The first few prime integers are 2, 3, 5, 7, 11 and 13.

A semiprime is a natural number that is the product of two (not necessarily distinct) prime numbers. The first few semiprimes are 4, 6, 9, 10, 14, 15, 21, 22, 25, 26.

You are given two non-empty arrays P and Q, each consisting of M integers. These arrays represent queries about the number of semiprimes within specified ranges.

Query K requires you to find the number of semiprimes within the range (P[K], Q[K]), where 1 ≤ P[K] ≤ Q[K] ≤ N.

For example, consider an integer N = 26 and arrays P, Q such that:
    P[0] = 1    Q[0] = 26
    P[1] = 4    Q[1] = 10
    P[2] = 16   Q[2] = 20

The number of semiprimes within each of these ranges is as follows:

        (1, 26) is 10,
        (4, 10) is 4,
        (16, 20) is 0.

Write a function:

    vector<int> solution(int N, vector<int> &P, vector<int> &Q);

that, given an integer N and two non-empty arrays P and Q consisting of M integers, returns an array consisting of M elements specifying the consecutive answers to all the queries.

For example, given an integer N = 26 and arrays P, Q such that:
    P[0] = 1    Q[0] = 26
    P[1] = 4    Q[1] = 10
    P[2] = 16   Q[2] = 20

the function should return the values [10, 4, 0], as explained above.

Write an efficient algorithm for the following assumptions:

        N is an integer within the range [1..50,000];
        M is an integer within the range [1..30,000];
        each element of arrays P, Q is an integer within the range [1..N];
        P[i] ≤ Q[i].
*/

vector<int> get_factors(int n) {
    vector<int> F(n+1,0);
    int i=2;
    while (i * i <= n) {
        if (F[i] == 0) {
            int k= i * i;
            while (k <= n) {
                if (F[k] == 0) {
                    F[k] = i;
                }
                k += i;
            }
        }
        i += 1;
    }

    return F;
}

bool is_semi_prime(int x, vector<int> & F) {
    int smallest_prime_factor = F[x];
    if (smallest_prime_factor > 0) {
        int quotient = x / smallest_prime_factor;
        return F[quotient] == 0;
    }
    return false;
}

vector<int>  get_semiprimes_count(int n) {
   vector<int> F = get_factors(n);
   vector<int> S(F.size(),0);
    int i=2;
    while (i <= n) {
    	S[i] = S[i-1];
        if (is_semi_prime(i, F)) {
            S[i]++;
        }
        i += 1;
    }

    return S;
}

vector<int> solution(int N, vector<int> &P, vector<int> &Q) {
	vector<int> semiprimes_count = get_semiprimes_count(N);
	vector<int> result(P.size(),0);
	for (int i = 0; i < (int)result.size(); i++) {
		result[i] = semiprimes_count[Q[i]] - semiprimes_count[P[i]-1];
	}

	return result;
}
// Driver program to test above function
int test() {
	vector<int> P{1,4,16};
	vector<int> Q{26,10,20};

	auto result = solution(66, P, Q);
	copy(result.begin(),result.end(),ostream_iterator<int>(cout,", "));
	cout << std::endl;
	return 0;
}
}

//Lesson 12 - Euclidean

namespace Euclidean {
int greatest_common_divisor_subtraction(int a, int b) {
	if (a == b)
		return a;

	if (a > b)
		return greatest_common_divisor_subtraction(a - b, b);
	else
		return greatest_common_divisor_subtraction(a, b - a);
}

int greatest_common_divisor_mod(int a, int b) {
	a = a % b;
	if (a == 0)
		return b;
	else
		return greatest_common_divisor_mod(b, a);
}

int greatest_common_divisor_bin(int a, int b, int res) {
	if (a == b)
		return res * a;
	else if ((a % 2 == 0) and (b % 2 == 0))
		return greatest_common_divisor_bin(a >> 1,  b >> 1, 2*res);
	else if (a % 2 == 0)
		return greatest_common_divisor_bin(a >> 1,  b, res);
	else if (b % 2 == 0)
		return greatest_common_divisor_bin(a,  b >> 1, res);
	else if (a > b)
		return greatest_common_divisor_bin(a - b,  b, res);
	else
		return greatest_common_divisor_bin(a,  b - a, res);
}

int least_common_multiple(int a, int b) {
	return (a*b) / greatest_common_divisor_mod(a, b);
}


// Function to return gcd of a and b
int gcd2(int a, int b)
{
    if (a == 0)
        return b;
    return gcd2(b%a, a);
}

void lowest_common_multiplier(int &den, int &num)
{
	int common_factor = greatest_common_divisor_mod(den,num);
    den = den/common_factor;
    num = num/common_factor;
}

void add_fraction(int num1, int den1, int num2,
                 int den2, int &num, int &den)
{
    int gcd_den = greatest_common_divisor_mod(den1,den2);
    den = (den1*den2) / gcd_den;
    num = (num1)*(den/den1) + (num2)*(den/den2);
    int common_factor = greatest_common_divisor_mod(den,num);
    den = den/common_factor;
    num = num/common_factor;
}

// Driver program
int test2()
{
    int num1=1, den1=500, num2=2, den2=1500, den, num;
    add_fraction(num1, den1, num2, den2, num, den);
    printf("%d/%d + %d/%d is equal to %d/%d\n", num1, den1,
                                   num2, den2, num, den);
    return 0;
}

int test() {
	int gcd1 = greatest_common_divisor_subtraction(24,9);
	std::cout << "greatest_common_divoisor_subtraction = " << gcd1 << std::endl;
	int gcd2 = greatest_common_divisor_mod(24,9);
	std::cout << "greatest_common_divisor_mod = " << gcd2 << std::endl;
	int gcd3 = greatest_common_divisor_bin(24,9,1);
	std::cout << "greatest_common_divisor_binary = " << gcd3 << std::endl;
	return 0;
}
};

namespace CountChocolates {

int greatest_common_divisor_binary(int a, int b, int res) {
	if (a == b)
		return res * a;
	else if ((a % 2 == 0) and (b % 2 == 0))
		return greatest_common_divisor_binary(a >> 1,  b >> 1, 2*res);
	else if (a % 2 == 0)
		return greatest_common_divisor_binary(a >> 1,  b, res);
	else if (b % 2 == 0)
		return greatest_common_divisor_binary(a,  b >> 1, res);
	else if (a > b)
		return greatest_common_divisor_binary(a - b,  b, res);
	else
		return greatest_common_divisor_binary(a,  b - a, res);
}

int least_common_multiple(int a, int b) {
	return (a*b) / greatest_common_divisor_binary(a, b, 1);
}

int solution(int N, int M) {
	return N / greatest_common_divisor_binary(N, M, 1);
}

int test() {
	int N = pow(3,9)*pow(2,14);
	int M = pow(2,14)*pow(2,14);
	int s1 = solution(N,M);
	std::cout << "CountChocolates_test 1 = " << s1 << std::endl;
	N = 947853;
	M = 4453;
	s1 = solution(N,M);
	std::cout << "CountChocolates_test 2 = " << s1 << std::endl;
	N = INT_MAX;
	M = INT_MAX;
	s1 = solution(N,M);
	std::cout << "CountChocolates_test 3 = " << s1 << std::endl;
	return 0;
}
};

namespace CommonPrimeDivisors {
int gcd(int a, int b)
{
   if (a % b == 0){
       return b;
   }
   return gcd(b, a % b);
}

int check(int a, int gcd_ab)
{
   //check if all the prime divisors of 'a' can be found
   //in the prime divisors of gcd(a,b).

   int rest = a / gcd_ab;

   //if gcd(a, b) % rest == 0, that means all the prime divisors
   //of 'rest' is included in the prime divisors of gcd(a,b).
   while (gcd_ab % rest != 0){

       int gcd_tmp = gcd(gcd_ab, rest);

       //if gcd(a,b) have 1 as the gcd with rest larger,
       //that means 'a / gcd(a,b)' contains some prime divisor that is not
       //found in the prime divisors of gcd(a,b).
       if (gcd_tmp == 1){
           return 0;
       }

       rest /= gcd_tmp;
   }

   return 1;
}

int solution(vector<int> &A, vector<int> &B)
{
   int Z = (int)A.size();
   int cnt = 0;

   int i;
   for (i = 0; i < Z; i++){
       int gcd_ab = gcd(A[i], B[i]);
       if (check(A[i], gcd_ab) && check(B[i], gcd_ab)){
           cnt++;
       }
   }

   return cnt;
}

int test() {
	vector<int> A = {15, 10, 3};
	vector<int> B = {75, 30, 5};
	std::cout << "CommonPrimeDivisors 1 = " << solution(A,B) << std::endl;
	return 0;
}
};


// Lesson 13 - Fibonacci numbers
namespace Ladders {
vector<int> solution(vector<int> &A, vector<int> &B) {

	auto L = A.size();
	vector<int> fibM(L+1,0);

	fibM[0] = 0;
	fibM[1] = 1;
	fibM[2] = 2;

	int i;
	for (i = 3; i <= (int)L; i++) {
		//0x 3FFF FFFF = 0B 0011 1111 1111 1111 1111 1111 1111 1111.
		//we cut off the 2 bits from MSB to avoid overflow by applying bitwise-and.
		fibM[i] = (fibM[i - 1] + fibM[i - 2]) & 0x3FFFFFFF;
	}

	vector<int> result(L);

	for (i = 0; i < (int)L; i++) {
		//it may be better to use fibM[A[i]] & ((1 << B[i]) - 1);
		result[i] = fibM[A[i]] % (1 << B[i]);
	}

	return result;
}

int test() {
	vector<int> A{4,4,5,5,1};
	vector<int> B{3,2,4,3,1};
	vector<int> solutionv = solution(A,B);
	std::cout << "Ladders =";
	copy(solutionv.begin(), solutionv.end(), ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	return 0;
}

};


namespace FibFrog {
/*
	The Fibonacci sequence is defined using the following recursive formula:
	    F(0) = 0
	    F(1) = 1
	    F(M) = F(M - 1) + F(M - 2) if M >= 2

	A small frog wants to get to the other side of a river. The frog is initially located at one bank of the river (position −1)
	and wants to get to the other bank (position N). The frog can jump over any distance F(K), where F(K) is the K-th Fibonacci number.
	Luckily, there are many leaves on the river, and the frog can jump between the leaves, but only in the direction of the bank at position N.

	The leaves on the river are represented in an array A consisting of N integers.
	Consecutive elements of array A represent consecutive positions from 0 to N − 1 on the river. Array A contains only 0s and/or 1s:

	        0 represents a position without a leaf;
	        1 represents a position containing a leaf.

	The goal is to count the minimum number of jumps in which the frog can get to the other side of the river (from position −1 to position N).
	The frog can jump between positions −1 and N (the banks of the river) and every position containing a leaf.

	For example, consider array A such that:
	    A[0] = 0
	    A[1] = 0
	    A[2] = 0
	    A[3] = 1
	    A[4] = 1
	    A[5] = 0
	    A[6] = 1
	    A[7] = 0
	    A[8] = 0
	    A[9] = 0
	    A[10] = 0

	The frog can make three jumps of length F(5) = 5, F(3) = 2 and F(5) = 5.

	Write a function:

	    int solution(vector<int> &A);

	that, given an array A consisting of N integers, returns the minimum number of jumps by which the frog can get to the other side of the river.
	If the frog cannot reach the other side of the river, the function should return −1.

	For example, given:
	    A[0] = 0
	    A[1] = 0
	    A[2] = 0
	    A[3] = 1
	    A[4] = 1
	    A[5] = 0
	    A[6] = 1
	    A[7] = 0
	    A[8] = 0
	    A[9] = 0
	    A[10] = 0

	the function should return 3, as explained above.

	Write an efficient algorithm for the following assumptions:

	        N is an integer within the range [0..100,000];
	        each element of array A is an integer that can have one of the following values: 0, 1.
*/

vector<int> fib_jumps{1,1,2,3,5,8,13};

int fibonacci(int N) {
	if (N < (int)fib_jumps.size() and fib_jumps[N] > 0) {
		return fib_jumps[N];
	}

	auto fib = fibonacci(N-1) + fibonacci(N-2);
	fib_jumps.push_back(fib);

	return fib;
}

void create_fib_jumps(int N) {
	for (int i = 7; i <= 30 and i < N; i++) {
		fibonacci(i);
	}
}

int solution(vector<int> &A) {
	int N = (int)A.size();
	create_fib_jumps(N);

	vector<int> reachable(A.size(),-1);
	for (auto jump : fib_jumps) {
		if (A[jump-1] == 1) {
			reachable[jump-1] = 1;
		}
	}

	int idx = 0;
	for (; idx < N; idx++) {
        if (A[idx] == 0 or reachable[idx] > 0) {
            continue;
        }

        int min_idx = -1;
        int min_value = 100000;

		for (auto jump : fib_jumps) {
			int previous_idx = idx - jump;
			if (previous_idx < 0) {
				break;
			}
			if (reachable[previous_idx] > 0 and min_value > reachable[previous_idx]) {
				min_value = reachable[previous_idx];
				min_idx = previous_idx;
			}

	        if (min_idx != -1) {
	            reachable[idx] = min_value +1;
	        }
		}
	}

	return reachable[idx];
}

int test() {
	vector<int> A{0,0,0,1,1,0,1,0,0,0,0};
	cout << "FibFrog=" << solution(A);
	return 0;
}

}

// Lesson 14 - Binary search
namespace MinMaxDivision {

int sum(vector<int> &A) {
    int total = 0;
    for (int i = 0; i < (int)A.size(); i++) {
        total += A[i];
    }
    return total;
}

int max(vector<int> &A) {
    int max = 0;
    for (int i = 0; i < (int)A.size(); i++) {
        if (max < A[i]) max = A[i];
    }
    return max;
}

int blockCount(int max, vector<int> &A) {
    int current = 0;
    int count = 1;
    for (int i = 0; i< (int)A.size(); i++) {
        if (current + A[i] > max) {
            current = A[i];
            count++;
        } else {
            current += A[i];
        }
    }
    return count;
}

int solution(int K, int M, vector<int> &A) {
    int high = sum(A);
    int low = max(A);

    int mid = 0;

    int smallestSum = 0;

    while (high >= low) {
        mid = (high + low) / 2;
        int numberOfBlock = blockCount(mid, A);

        if (numberOfBlock > K) {
            low = mid + 1;
        } else if (numberOfBlock <= K) {
            smallestSum = mid;
            high = mid - 1;
        }

    }
    return smallestSum;
}

int test() {
	vector<int> A{2, 1, 5, 1, 2, 2, 2};
	std::cout << "MinMaxDivision = " << solution(3, 5, A)  << std::endl;
	return 0;
}

};

namespace NailingPlanks {

bool nails_enough(int j,vector<int> &A, vector<int> &B, vector<int> &C)
{
    std::vector<int> used_nails (C.begin(),C.begin()+j);
    sort(used_nails.begin(),used_nails.end());
    // binary search again for fitted nail
    for(int j = 0; j < (int)A.size();j++)
    {
        int last = (int)used_nails.size()-1;
        int mid = 0;
        int bgn = 0;
        bool found = false;
        while (bgn <= last)
        {
            mid = (last+bgn)/2;
            if (used_nails[mid] >= A[j] && used_nails[mid] <= B[j]) // fit
            {
                found = true;
                break;
            }
            if(used_nails[mid] < A[j])
            {
                bgn=mid+1;
            }else if(used_nails[mid] > B[j])
            {
                last = mid-1;
            }
        }
        if (found == false)
            return false;
    }
    return true;
}

int solution(vector<int> &A, vector<int> &B, vector<int> &C) {
    int last = (int)C.size();
    int bgn = 0;
    int mid=0;
    int result =-1;
    while(bgn<=last)
    {
        mid = (last+bgn)/2;
        if(nails_enough(mid,A,B,C))
        {
            last=mid-1;
            result = mid;
        } else
            bgn=mid+1;
    }
    return result;
}

int test() {
	vector<int> A{1,4,5,8};
	vector<int> B{4,5,9,10};
	vector<int> C{2,6,7,10,4};

	std::cout << "NailingPlanks = " << solution(A,B,C) << std::endl;
	return 0;
}

};

// Lesson 15 - Caterpillar


namespace MinMaxDivision_test {
		// check if it can be divided by using the minMaxSum = "mid", into K blocks ?
		 bool checkDivisable(int mid, int k, std::vector<int> a){
			int numBlockAllowed = k;
			int currentBlockSum = 0;

			for(int i=0; i< (int)a.size(); i++){
				currentBlockSum = currentBlockSum + a[i];

				if(currentBlockSum > mid){ // means: need one more block
					numBlockAllowed--;
					currentBlockSum = a[i]; // note: next block
				}

				if(numBlockAllowed == 0){
					return false; // cannot achieve minMaxSum = "mid"
				}
			}

			// can achieve minMaxSum = "mid"
			return true;
		}

     int solution(int K, int M, std::vector<int> A) {
        // main idea:
        // The goal is to find the "minimal large sum"
        // We use "binary search" to find it (so, it can be fast)

        // We assume that the "min max Sum" will be
        // between "min" and "max", ecah time we try "mid"

        int minSum = 0;
        int maxSum = 0;
        for(int i=0; i<(int)A.size(); i++){
            maxSum = maxSum + A[i];          // maxSum: sum of all elements
            minSum = max(minSum, A[i]); // minSum: at least one max element
        }

        int possibleResult = maxSum; // the max one must be an "ok" result

        // do "binary search" (search for better Sum)
        while(minSum <= maxSum){
            // define "mid" (binary search)
            int midSum = (minSum + maxSum) /2;

            // check if it can be divided by using
            // the minMaxSum = "mid", into K blocks ?
            bool ok = checkDivisable(midSum, K, A);

            // if "ok", means that we can try "smaller"
            // otherwise ("not ok"), we have to try "bigger"
            if(ok == true){
                possibleResult = midSum; // mid is "ok"
                // we can try "smaller"
                maxSum = midSum - 1;
            }
            else{ // "not ok"
            // we have to try "bigger"
                minSum = midSum + 1;
            }
            // go back to "binary search" until "min > max"
        }

        return possibleResult;
    }

	int test() {
		std::vector<int> A1{2,1,5,1,2,2};
		std::cout << "MinMaxDivision_test{2,1,5,1,2,2}=" << solution(3,5,A1) << std::endl;
		return 0;
	}
};

namespace NailingPlanks_test {

bool nails_enough(int j,vector<int> &A, vector<int> &B, vector<int> &C)
{
    std::vector<int> used_nails (C.begin(),C.begin()+j);
    sort(used_nails.begin(),used_nails.end());
    // binary search again for fitted nail
    for(int j = 0; j < (int)A.size();j++)
    {
        int last = (int)used_nails.size()-1;
        int mid = 0;
        int bgn = 0;
        bool found = false;
        while (bgn <= last)
        {
            mid = (last+bgn)/2;
            if (used_nails[mid] >= A[j] && used_nails[mid] <= B[j]) // fit
            {
                found = true;
                break;
            }
            if(used_nails[mid] < A[j])
            {
                bgn=mid+1;
            }else if(used_nails[mid] > B[j])
            {
                last = mid-1;
            }
        }
        if (found == false)
            return false;
    }
    return true;
}

int solution(vector<int> &A, vector<int> &B, vector<int> &C) {
    int last = (int)C.size();
    int bgn = 0;
    int mid=0;
    int result =-1;
    while(bgn<=last)
    {
        mid = (last+bgn)/2;
        if(nails_enough(mid,A,B,C))
        {
            last=mid-1;
            result = mid;
        } else
            bgn=mid+1;
    }
    return result;
}

int test() {
	vector<int> A{1,4,5,8};
	vector<int> B{4,5,9,10};
	vector<int> C{2,6,7,10,4};

	std::cout << "NailingPlanks=" << solution(A,B,C) << std::endl;
	return 0;
}

};

namespace Ladders_test {
vector<int> solution(vector<int> &A, vector<int> &B) {

	auto L = A.size();
	vector<int> fibM(L+1,0);

	fibM[0] = 0;
	fibM[1] = 1;
	fibM[2] = 2;

	int i;
	for (i = 3; i <= (int)L; i++) {
		//0x 3FFF FFFF = 0B 0011 1111 1111 1111 1111 1111 1111 1111.
		//we cut off the 2 bits from MSB to avoid overflow by applying bitwise-and.
		fibM[i] = (fibM[i - 1] + fibM[i - 2]) & 0x3FFFFFFF;
	}

	vector<int> result(L);

	for (i = 0; i < (int)L; i++) {
		//it may be better to use fibM[A[i]] & ((1 << B[i]) - 1);
		result[i] = fibM[A[i]] % (1 << B[i]);
	}

	return result;
}

int test() {
	vector<int> A{4,4,5,5,1};
	vector<int> B{3,2,4,3,1};
	vector<int> solutionv = solution(A,B);
	std::cout << "Ladders_test=";
	copy(solutionv.begin(), solutionv.end(), ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	return 0;
}

}


int test_import() {
	StoneWall::test();
	return 0;
}

namespace Caterpillar {

template<typename Iterator>
bool condition(int & total,Iterator front_itr,int s) {
	 if ( (total + *front_itr) <= s) {
       total += *front_itr;
       std::advance(front_itr,1);
       return true;
	 }

	 return false;
}

int solution(vector<int> &A, int s) {
        auto front_itr = A.begin();
        auto back_itr = front_itr;
        int total = 0;
        while(back_itr != A.end()) {
                while (front_itr != A.end()) {
                      // keep moving front along, stretching range
                	if (not condition(total,front_itr,s))
                		break;
                	/*
                	 if ( (total + *front_itr) <= s) {
                        total += *front_itr;
                        std::advance(front_itr,1);
                	 }
                	 else {
                		 break;
                	 }
                	 */
                }
                if (total == s) {
                        std::cout << "Found the target(" << s << ") summing between [";
                        std::copy(back_itr,front_itr,std::ostream_iterator<int>(std::cout," "));
                        std::cout << "]\n";
                        return s;
                }
                // Possible s is captured in total some where so
                // removing the back value from range
                // move back up one, shrinking range
                total -= *back_itr;
                std::advance(back_itr,1);
        }
        return -1;
}

int test() {
        vector<int> A{1,4,5,8,4,5,9,10,2,6,7,10,4};
        std::cout << "Catipillar test=" << solution(A,31) << std::endl;
        return 0;
}
};

namespace Triangles {

int solution(vector<int> &A) {
        // write your code in C++14 (g++ 6.2.0)
        auto n = A.size();
        // Sort the array elements in non-decreasing order
        std::sort(A.begin(), A.end());

        // Initialize count of triangles
        int count = 0;

        // Fix the first element. We need to run till n-3
        // as the other two elements are selected from
        // arr[i+1...n-1]
        for (int x = 0; x < (int) n - 2; ++x) {
                // Initialize index of the rightmost third
                // element
                int z = x + 2;

                // Fix the second element
                for (int y = x + 1; y < (int) n; ++y) {
                        // Find the rightmost element which is
                        // smaller than the sum of two fixed elements
                        // The important thing to note here is, we
                        // use the previous value of k. If value of
                        // arr[i] + arr[j-1] was greater than arr[k],
                        // then arr[i] + arr[j] must be greater than k,
                        // because the array is sorted.
                        while (z < (int) n && A[x] + A[y] > A[z])
                                ++z;

                        // Total number of possible triangles that can
                        // be formed with the two fixed elements is
                        // k - j - 1. The two fixed elements are arr[i]
                        // and arr[j]. All elements between arr[j+1]/ to
                        // arr[k-1] can form a triangle with arr[i] and arr[j].
                        // One is subtracted from k because k is incremented
                        // one extra in above while loop.
                        // k will always be greater than j. If j becomes equal
                        // to k, then above loop will increment k, because arr[k]
                        // + arr[i] is always greater than arr[k]
                        if (z > y)
                                count += z - y - 1;
                }
        }

        return count;
}

int test() {
        vector<int> A{10,2,5,1,8,12};
        std::cout << "Triangles = " << solution(A) << std::endl;
        return 0;
}


};

namespace MinAbsSumOfTwo
{

/*
Let A be a non-empty array consisting of N integers.

The abs sum of two for a pair of indices (P, Q) is the absolute value |A[P] + A[Q]|, for 0 ≤ P ≤ Q < N.

For example, the following array A:
  A[0] =  1
  A[1] =  4
  A[2] = -3

has pairs of indices (0, 0), (0, 1), (0, 2), (1, 1), (1, 2), (2, 2).
The abs sum of two for the pair (0, 0) is A[0] + A[0] = |1 + 1| = 2.
The abs sum of two for the pair (0, 1) is A[0] + A[1] = |1 + 4| = 5.
The abs sum of two for the pair (0, 2) is A[0] + A[2] = |1 + (−3)| = 2.
The abs sum of two for the pair (1, 1) is A[1] + A[1] = |4 + 4| = 8.
The abs sum of two for the pair (1, 2) is A[1] + A[2] = |4 + (−3)| = 1.
The abs sum of two for the pair (2, 2) is A[2] + A[2] = |(−3) + (−3)| = 6.

Write a function:

    int solution(vector<int> &A);

that, given a non-empty array A consisting of N integers, returns the minimal abs sum of two for any pair of indices in this array.

For example, given the following array A:
  A[0] =  1
  A[1] =  4
  A[2] = -3

the function should return 1, as explained above.

Given array A:
  A[0] = -8
  A[1] =  4
  A[2] =  5
  A[3] =-10
  A[4] =  3

the function should return |(−8) + 5| = 3.

Write an efficient algorithm for the following assumptions:

        N is an integer within the range [1..100,000];
        each element of array A is an integer within the range [−1,000,000,000..1,000,000,000].


 */
int solution1(vector<int> &A) {
   int minAbsSumOfTwo = INT_MAX;

   int back_itr =  0;
   int front_itr = back_itr;
   int running_sum = 0;
   while(back_itr < (int)A.size()) {
	   while (front_itr !=(int)A.size()) {
		   // keep moving front along, stretching range
		   auto current_sum = A[front_itr] + A[back_itr];
		   if (running_sum > running_sum + current_sum ) {
			   back_itr = front_itr;
		   }
		   auto abs_sum = abs(A[front_itr] + A[back_itr]);
		   std::cout << "abs_sum " << "(" << back_itr << "," << front_itr << ") = |" << A[back_itr] <<  " + " << A[front_itr] << "| = " << abs(A[front_itr] + A[back_itr]) << std::endl;
		   if (abs_sum < minAbsSumOfTwo) {
			   minAbsSumOfTwo = abs_sum;
		   }
		   front_itr++;
	   }
	   back_itr++;
   }

   return minAbsSumOfTwo;
}


int compare_int(const void *a, const void *b)
{
   //don't do 'return *(int*)a - *(int*)b;',
   //as it can cause underflow or overflow.

   if (*(int*)a == *(int*)b){
       return 0;
   }

   if (*(int*)a < *(int*)b){
       return -1;
   }

   return 1;
}

int solution2(vector<int> &A)
{
    //first we sort in the ascending order
    std::sort(A.begin(), A.end());
    int N = (int)A.size();
    int l = 0;
    int r = N - 1;

    //the initial value for the min
    int min = abs(A[0] + A[0]);

    while(l <= r){

        int lval = abs(A[l] * 2);
        int rval = abs(A[r] * 2);
        int both = abs(A[l] + A[r]);

        //update the min value
        if (lval < min){
            min = lval;
        }
        if (rval < min){
            min = rval;
        }
        if (both < min){
            min = both;
        }

        //we A[l] >=0, we have the smallest number already.
        if (A[l] >= 0){
            break;
        }

        //move the positions.
        if (lval < rval){
            r--;
        }
        else if (lval > rval){
            l++;
        }
        else {
            r--;
            l++;
        }

    }

    return min;
}

int test() {
	vector<int> A1{1,4,-3};
    std::cout << "MinAbsSumOfTwo 1 =" << solution1(A1) << std::endl;
	vector<int> A2{ -8, 4, 5, -10, 3};
    std::cout << "MinAbsSumOfTwo 2 =" << solution1(A2) << std::endl;
    return 0;
}
};


namespace CountDistinctSlicesCaterpillar {

int solution(int M, vector<int> &A) {
	vector<bool> slice(M + 1, false);
	auto front_itr = A.begin();
	auto back_itr = front_itr;
	int max_slices = 0;
    std::cout << "slice=[";
    for (int i = 0; i < (int)slice.size(); i++) {
    	cout << " [" << i << "]=" << std::boolalpha << slice[i];
    }
    std::cout << " ]" << std::endl;
	std::cout << "solution left(" << back_itr- A.begin() << "),right(" << front_itr- A.begin() << ") total:" << max_slices << std::endl;

	while (back_itr != A.end()) {
		if (front_itr != A.end() and slice[*front_itr] == false) {
			slice[*front_itr] = true;
			front_itr++;
            std::cout << "slice=[";
            for (int i = 0; i < (int)slice.size(); i++) {
            	cout << " [" << i << "]=" << std::boolalpha << slice[i];
            }
            std::cout << " ]" << std::endl;
			std::cout << "solution left(" << back_itr- A.begin() << "),right(" << front_itr- A.begin() << ") total:" << max_slices << std::endl;
		}
		else {
			max_slices += (distance(back_itr, front_itr));
			if(max_slices > 1000000000) {
				return 1000000000;
			}
			//back_itr = front_itr;
			slice[*back_itr] = false;
			//back_itr = front_itr;
			back_itr++;
            std::cout << "slice=[";
            for (int i = 0; i < (int)slice.size(); i++) {
            	cout << " [" << i << "]=" << std::boolalpha << slice[i];
            }
            std::cout << " ]" << std::endl;
			std::cout << "solution left(" << back_itr- A.begin() << "),right(" << front_itr- A.begin() << ") total:" << max_slices << std::endl;
		}
	}

	return max_slices;
}

struct tracking {
	vector<bool> slice;
	int max_slices = 0;
    int back = 0;
    int front = 0;

	tracking(int M) {
		slice.resize(M+1,false);
	}

	bool condition(vector<int> &A) {
		return slice[A[front]] == false;
	}

	void inc_front(vector<int> &A) {
		slice[A[front]] = true;
		front++;
	}

	void inc_back(vector<int> &A) {
		max_slices += front - back;
		slice[A[back]] = false;
		back++;
	}

	bool check_early_exit(vector<int> &A) {
		return max_slices > 1000000000;
	}

	void print(vector<int> &A) {
        std::cout << "slice=[";
        for (int i = 0; i < (int)slice.size(); i++) {
        	cout << " [" << i << "]=" << std::boolalpha << slice[i];
        }
        std::cout << " ]" << std::endl;
        std::cout << "solution2 back(" << back << "),front(" << front << ") total:" << max_slices << std::endl;
	}
};

int solution2(int M, vector<int> &A) {
	tracking cTracking(M);
    std::cout << "solution2 back(" << cTracking.back << "),front(" << cTracking.front << ") total:" << cTracking.max_slices << std::endl;
    while (cTracking.back != (int)A.size()) {
        if (cTracking.front != (int)A.size() and cTracking.condition(A)) {
            cTracking.inc_front(A);
            cTracking.print(A);
        }
        else {
        	cTracking.inc_back(A);

            if(cTracking.check_early_exit(A)) {
                return 1000000000;
            }

            cTracking.print(A);
        }
    }

    return cTracking.max_slices;
}

int test() {
	std::vector<int> A { 3, 4, 5, 5, 2 };
	std::cout << "CountDistinctSlicesCaterpillar 1 {3,4,5,5,2}=" << solution(6, A)
			<< std::endl;
	std::cout << "CountDistinctSlicesCaterpillar 2 {3,4,5,5,2}=" << solution2(6, A)
			<< std::endl;
	return 0;
}
}



namespace CountDistinctSlices {
/*
 An integer M and a non-empty array A consisting of N non-negative integers are given. All integers in array A are less than or equal to M.

 A pair of integers (P, Q), such that 0 ≤ P ≤ Q < N, is called a slice of array A. The slice consists of the elements A[P], A[P + 1], ..., A[Q]. A distinct slice is a slice consisting of only unique numbers. That is, no individual number occurs more than once in the slice.

 For example, consider integer M = 6 and array A such that:

 A[0] = 3
 A[1] = 4
 A[2] = 5
 A[3] = 5
 A[4] = 2
 There are exactly nine distinct slices: (0, 0), (0, 1), (0, 2), (1, 1), (1, 2), (2, 2), (3, 3), (3, 4) and (4, 4).

 The goal is to calculate the number of distinct slices.

 Write a function:

 int solution(int M, vector<int> &A);

 that, given an integer M and a non-empty array A consisting of N integers, returns the number of distinct slices.

 If the number of distinct slices is greater than 1,000,000,000, the function should return 1,000,000,000.

 For example, given integer M = 6 and array A such that:

 A[0] = 3
 A[1] = 4
 A[2] = 5
 A[3] = 5
 A[4] = 2
 the function should return 9, as explained above.

 Write an efficient algorithm for the following assumptions:

 N is an integer within the range [1..100,000];
 M is an integer within the range [0..100,000];
 each element of array A is an integer within the range [0..M].
 */

int solution(int M, vector<int> &A) {
	if ((int) A.size() == 1)
		return 1;
	int N = (int) A.size();
	int max_slices = 0;
	std::vector<int> m(M+1,-1);

	int r = 0;
	int l = -1;
	for (; r < N; r++) {
		if (m[A[r]] > l) {
			l = m[A[r]];
			std::cout << "CountDistinctSlices Dup back(" << l << "),front(" << r << ")" << std::endl;
		}


		max_slices += r - l;
		std::cout << "CountDistinctSlices back(" << l << "),front(" << r << ") max_slices:" << max_slices << std::endl;

		m[A[r]] = r;
		if (max_slices > 1000000000) {
			return 1000000000;
		}
	}

	return max_slices;
}

int test() {
	std::vector<int> A { 3, 4, 5, 5, 2 };
	std::cout << "CountDistinctSlices{3,4,5,5,2}=" << solution(6, A)
			<< std::endl;
	return 0;
}
}



// Lesson 16 - Greedy algorithms
namespace TieRopes {
/*

 There are N ropes numbered from 0 to N − 1, whose lengths are given in an array A,
 lying on the floor in a line. For each I (0 ≤ I < N), the length of rope I on the line is A[I].

 We say that two ropes I and I + 1 are adjacent.
 Two adjacent ropes can be tied together with a knot,
 and the length of the tied rope is the sum of lengths of both ropes.
 The resulting new rope can then be tied again.

 For a given integer K, the goal is to tie the ropes in such a way that
 the number of ropes whose length is greater than or equal to K is maximal.
 */

int solution(int K, vector<int> &A) {
	int num_ropes = 0;
	int current_len = 0;
	for (auto rope_len : A) {
		current_len += rope_len;
		if (current_len >= K) {
			num_ropes++;
			current_len = 0;
		}
	}
	return num_ropes;
}

int test() {
	std::vector<int> A1 { 1, 2, 3, 4, 1, 1, 3 };
	std::cout << "ropes{1,2,3,4,1,1,3}=" << solution(4, A1) << std::endl;
	return 0;
}

}

namespace DynamicCoinChanging {
/*
Consider n denominations,0< c0c1. . .cn−1.
The algorithm processes the respective denominations and calculates the minimum number of coins needed to pay every amount from 0 to k.
When considering each successive denomination, we use the previously calculated results for the smaller amounts.
 */

void dynamic_coin_changing(vector<int> &coins, int k) {
		int n = (int)coins.size();
		//create two-dimensional array with all zeros
		vector<vector<int>> dp(k + 1,vector<int>(n + 1));
/*
		dp[0] = [0] + [MAX_INT]*k
		for i inxrange(1, n + 1):
		 for j in xrange(C[i - 1]):
		  dp[i][j] = dp[i - 1][j]
		 for j in xrange(C[i - 1], k + 1):
							 dp[i][j] = min(dp[i][j - C[i - 1]] + 1, dp[i - 1][j])
							 returndp[n]
							 */
}
}

namespace Flags {
/*

A non-empty array A consisting of N integers is given.

A peak is an array element which is larger than its neighbours. More precisely, it is an index P such that 0 < P < N − 1 and A[P − 1] < A[P] > A[P + 1].

For example, the following array A:
    A[0] = 1
    A[1] = 5
    A[2] = 3
    A[3] = 4
    A[4] = 3
    A[5] = 4
    A[6] = 1
    A[7] = 2
    A[8] = 3
    A[9] = 4
    A[10] = 6
    A[11] = 2

has exactly four peaks: elements 1, 3, 5 and 10.

You are going on a trip to a range of mountains whose relative heights are represented by array A, as shown in a figure below. You have to choose how many flags you should take with you.
The goal is to set the maximum number of flags on the peaks, according to certain rules.

Flags can only be set on peaks. What's more, if you take K flags, then the distance between any two flags should be greater than or equal to K.
The distance between indices P and Q is the absolute value |P − Q|.

For example, given the mountain range represented by array A, above, with N = 12, if you take:

        two flags, you can set them on peaks 1 and 5;
        three flags, you can set them on peaks 1, 5 and 10;
        four flags, you can set only three flags, on peaks 1, 5 and 10.

You can therefore set a maximum of three flags in this case.

Write a function:

    int solution(vector<int> &A);

that, given a non-empty array A of N integers, returns the maximum number of flags that can be set on the peaks of the array.

For example, the following array A:
    A[0] = 1
    A[1] = 5
    A[2] = 3
    A[3] = 4
    A[4] = 3
    A[5] = 4
    A[6] = 1
    A[7] = 2
    A[8] = 3
    A[9] = 4
    A[10] = 6
    A[11] = 2

the function should return 3, as explained above.

Write an efficient algorithm for the following assumptions:

        N is an integer within the range [1..400,000];
        each element of array A is an integer within the range [0..1,000,000,000].
 */

vector<bool> get_peaks(vector<int> &A) {
	vector<bool> peaks(A.size(), false);
	for (int i = 1; i < (int)A.size() - 1; i++) {
		if (A[i] > A[i - 1] and A[i] > A[i + 1]) {
			peaks[i] = true;
		}
	}
	return peaks;
}

bool check(vector<int> &A, vector<bool> &peaks, int x) {
	int N = A.size();
	int flags = x;
	int pos = 0;
	while (pos < N and flags > 0) {
		if (peaks[pos]) {
			flags -= 1;
			pos += x;
		} else {
			pos++;
		}
	}
	return flags == 0;
}

int solution(vector<int> &A) {
	int flag_count  = 0;
	auto peaks = get_peaks(A);
	int max_flags  = std::count_if(peaks.begin(),peaks.end(),[](bool v){ return v;});
	int beg = 1;
	int end = max_flags;

	while(beg <= end) {
		int mid = (beg + end) / 2;
		if(check(A,peaks,mid)) {
			beg = mid + 1;
			flag_count = mid;
		}
		else {
			end = mid - 1;
		}
	}

	return flag_count;
}


int test() {
	std::vector<int> A1 { 1, 5, 3, 4, 3, 4, 1, 2, 3, 4, 6, 2 };
	std::cout << "flags 1 { 1, 5, 3, 4, 3, 4, 1, 2, 3, 4, 6, 2 }=" << solution(A1) << std::endl;

	std::vector<int> A2 { 7, 10, 4, 5, 7, 4, 6, 1, 4, 3, 3, 7 };
	std::cout << "flags 2 { 1, 5, 3, 4, 3, 4, 1, 2, 3, 4, 6, 2 }=" << solution(A2) << std::endl;

	std::vector<int> A3 {9, 9, 4, 3, 5, 4, 5, 2, 8, 9, 3, 1};
	std::cout << "flags 3 { 9, 9, 4, 3, 5, 4, 5, 2, 8, 9, 3, 1}=" << solution(A3) << std::endl;

	return 0;
}

}


int main() {
	CodilityDemo::test();

	// Codilty tasks
	// Merge sort like algo, merging 2 numbers together
	task1::test();
	// Swap counting to sort an array, only one allowed
	task3::test();
	task4::test();

	// Lesson 1 - Iterations
	BinaryGap::test();

	// Lesson 2 - Arrays
	OddOccurrencesInArray::test();
	CyclicRotation::test();

	// Lesson 3 - Time Complexity
	FrogJmp::test();
	PermMissingElem::test();
	TapeEquilibrium::test();

	// Lesson 4 - Counting Elements
	MaxCounters::test();
	MissingInteger::test();
	PermCheck::test();
	FrogRiverOne::test();

	// Lesson 5 Prefix Sums
	PassingCars::test();
	GenomicRangeQuery::test();
	MinAvgTwoSlice::test();
	CountDiv::test();

	//Lesson 6 Sorting
	MaxProductOfThree::test();
	Distinct::test();
	Triangle::test();
	NumberOfDiscIntersections::test();

	//Lesson 7 Stacks and Queues
	Brackets::test();
	Fish::test();
	Nesting::test();
	StoneWall::test();

	//Lesson 8 Leader
	Dominator::test();
	EquiLeader::test();

	//Lesson 9 Maximum slice problem
	max_slice::test();
	MaxProfit::test();
	MaxSliceSum::test();
	MaxDoubleSliceSum::test();

	// Lesson 10 - Prime and composite numbers
	Divisors::test();
	CountFactors::test();

	// Lesson 11
	SieveOfEratosthenes::test();
	CountSemiprimes::test();

	// Lesson 12 - Euclidean algorithm
	Euclidean::test();
	Euclidean::test2();
	CountChocolates::test();
	CommonPrimeDivisors::test();

	// Lesson 13 - Fibonacci numbers
	Ladders::test();
	FibFrog::test();

	// Lesson 14 - Binary search algorithm
	MinMaxDivision::test();
	NailingPlanks::test();

	// Lesson 15 Caterpillar
	Caterpillar::test();
	Triangles::test();
	MinAbsSumOfTwo::test();
	//AbsDistinct::test();
	CountDistinctSlices::test();
	CountDistinctSlicesCaterpillar::test();

	// Lesson 16 - Greedy algorithms
	TieRopes::test();

	// Lesson 17 - Dynamic Programming


	// Flags
	Flags::test();

	return 0;
}
