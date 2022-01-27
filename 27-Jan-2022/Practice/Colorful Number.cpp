// Question URL => https://www.interviewbit.com/problems/colorful-number/



int Solution::colorful(int A) {
    
    map<int, bool> store;           // Initializing an ordered map to store the values already there since insertion is not the priority here. Lookup is our priority
    vector<int> individuals;        // Initializing a vector to store all the individual numbers of the input numbers in order

    // storing all the individual numbers inside the ordered map if not already present. If the individual number is already present in the map,
    // then, the number is not a colorful number and the function immediately returns 0. 
    while(A>0) {
        if(store[A%10]) {               // checking whether the individual number is already present in the ordered map or not
            return 0;                   // returning 0 if already present, since the number is not a colorful number
        }
        store[A%10] = true;             // storing the number inside the ordered map
        individuals.push_back(A%10);    // storing the number inside the vector for future reference
        A /= 10;                        // shortening the input number and removing the individual number already processed
    }

    for(int i=2; i<=individuals.size(); i++) {                  // A loop for deciding the number of consecutive numbers to be considered
        for(int j=0; j<individuals.size()-i+1; j++) {           // A for loop for deciding the starting index from where the consecutive numbers are to be considered
            int temp = 1;                                       // A variable for storing the multiplication of the consecutive numbers
            for(int k=j; k<j+i; k++) {                          // A loop for looping over the consecutive numbers
                temp *= individuals[k];                         // multiplying the consectuve numbers one-by-one
            }
            
            if(store[temp]) {                                   // returning 0 if the number already exists in the ordered mqp
                return 0;
            }
            
            store[temp] = true;                                 // storing the number inside the ordered map
            
        }
    }

    // Since the function didn't return anything until this point, the number is a Colorful Number
    return 1;

}