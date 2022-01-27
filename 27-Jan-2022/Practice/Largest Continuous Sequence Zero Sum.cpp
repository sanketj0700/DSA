// Question URL => https://www.interviewbit.com/problems/largest-continuous-sequence-zero-sum/



// Logic used :
// For example, we have an array [1, -3, 3, -2, 2]
// In this array, we have 3 sequences with sum 0 => [-3, 3] | [-2, 2] | [-3, 3, -2, 2]
// The largest continuous sequence is what we are interested in. Hence, among the 3 mentioned above, [-3, 3, -2, 2] is of our sole interest
// If we have a look at an array that contains sum of all the numbers from index 0 to index i in the original array, it will look something like this
// [1, -2, 1, -1, 1]
// Observing the sum array above, we can come up with a concept
// CONCEPT => If the values at index i and j (i<j) of the sum array are same, then the sum from index i+1 to j 0
// using the above concept, we can store indexes of the given array corresponding to the sum until that index as a key-value pair
// later, we can calculate the distance/length by subtracting the first and last value of each array corresponding to each key (sum)
// in case 2 lengths contradict, we will consider the one who's start index is the smaller one

vector<int> Solution::lszero(vector<int> &A) {
    
    // an ordered map to store (sum, index) key-value pair.
    // since there coud be more than one index having same sum upto them, the value mapped to each key is a vector
    // each vector will contain the index upto which the sum is same as the key to which the vectoris mapped
    map<int, vector<int>> store;
    
    
    // sum until index i, initially 0
    int sum = 0;

    // since sum currently is 0 and it is possible for it to be 0 once again somewhere, we are storing it in the map with a value of -1 as the index in the vector corresponding to it
    store[sum].push_back(-1);

    // storing index of the array corresponding to the sum upto that index in the map
    for(int i=0; i<A.size(); i++) {
        sum += A[i];
        store[sum].push_back(i);
    }

    // variables for storing the length of the sequence and starting index
    int largest = 0;
    int start = 0;

    // iterating over the entire map key-by-key
    for(auto i: store) {
        // checking if the size of the vector corresponding to the key is greater than 1 or not
        // this is essential to check, because if length is equal to 1, there is no such sequence with zero sum correspondingto the key
        if(i.second.size()>1) {
            
            // computing length of the largest sequence with sum zero
            int temp = i.second.back()-i.second[0];
            
            // if the length registered largest until now and the length this time are same, update start with the lower number
            if(temp==largest) {
                start = min(start, i.second[0] + 1);
            } else {
                // here, if the new length is larger than the one registered until now, update the largest length as well as the start index of the sequence
                temp = largest;
                largest = max(largest, i.second.back()-i.second[0]);
                if(temp!=largest) {
                    start = i.second[0] + 1;
                }
            }
        }
    }

    // storing the values in the largest sequence in a vector to return
    vector<int> result;
    for(int i=0; i<largest; i++) {
        result.push_back(A[i+start]);
    }

    return result;

}
