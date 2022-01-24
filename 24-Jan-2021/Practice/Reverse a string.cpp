//   Function for reversing a given string
string reverseWord(string str){
  
//   IMPLEMENTING ENTIRE LOGIC
  for(int i=0; i<=(str.length()-1)/2; i++) {
      char temp = str[i];
      str[i] = str[length-i-1];
      str[length-i-1] = temp;
  }
  
  return str;
  
  
// USING STL FUNCTION (from the "algorithm" library)
  reverse(str.begin(), str.end());
  return str;

}