#include <iostream>
#include <string>

int main(){

    std::string s0;
    std::string s1 = "Apple";
    std::string s2 = "Banana";
    std::string s3 = "Kiwi";
    std::string s4 = "apple";
    std::string s5 = s1; 
    std::string s6 = s1.substr(3,2);
    std::string s7(10, 'X');

    // Initialization
    std::cout << "\nInitialization\n-----------------" << std::endl;
    std::cout << s0 << std::endl;
    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;
    std::cout << s3 << std::endl;
    std::cout << s4 << std::endl;
    std::cout << s5 << std::endl;
    std::cout << s6 << std::endl;
    std::cout << s7 << std::endl;

    // Comparison
    std::cout << "\nComparison\n-----------------" << std::endl;
    std::cout << std::boolalpha;
    std::cout << s1  << " == " << s5 << ": " << (s1 == s5) << std::endl; 		           
    std::cout << s1  << " == " << s2 << ": " << (s1 == s2) << std::endl;
    std::cout << s1  << " == " << s4 << ": " << (s1 == s4) << std::endl;	           
    std::cout << s1  << " != " << s2 << ": " << (s1 != s2) << std::endl;		           
    std::cout << s1  << " < " << s2 << ": " << (s1 < s2) << std::endl;;		           
    std::cout << s2  << " > " << s1 << ": " <<(s2 > s1) << std::endl;		         
    std::cout << s4  << " < " << s5 << ": " <<(s4 < s5) << std::endl;		            
    std::cout << s1  << " == " << "Apple" << ": " <<(s1 == "Apple") << std::endl;;	       

    // Assignment 
    std::cout << "\nAssignment\n-----------------" << std::endl;
    s1 = "Watermelon";
    std::cout << "s1 is now: " << s1 << std::endl;   
    s2 = s1;
    std::cout << "s2 is now: " << s2 << std::endl;    
    s3 = "Frank";
    std::cout << "s3 is now: " << s3 << std::endl;   
    s3[0] = 'C';    
    std::cout << "s3 change first letter to 'C': "  << s3 << std::endl;  
    s3.at(0) = 'P';
    std::cout << "s3 change first letter to 'P': "  << s3 << std::endl;   


    // Concatenation
    std::cout << "\nConcatenation\n-----------------" << std::endl;
    s3 =  s5 + " and " + s2 + " juice";   
    std::cout << "s3 is now: " << s3 << std::endl;   

    // For Loop
    std::cout << "\nLooping\n-----------------" << std::endl;    
    s1 = "Apple";
    for (int i = 0; i < s1.length(); ++i) 
        std::cout << s1.at(i);     
    std::cout << std::endl;
    
    // Range-based for loop
    for (char c : s1)
        std::cout << c;     
    std::cout << std::endl;

    // Substring
    std::cout << "\nSubstring\n-----------------" << std::endl;    
    s1 = "This is a test";
    std::cout << s1.substr(0,4) << std::endl;	   
    std::cout << s1.substr(5,2) << std::endl;	   
    std::cout << s1.substr(10,4) << std::endl;   	

    // Erase
    std::cout << "\nErase\n-----------------" << std::endl; 
    s1.erase(0,5);    
    std::cout << "s1 is now: " << s1<< std::endl;    

    // getline
    std::cout << "\ngetline\n-----------------" << std::endl; 
    std::string full_name;
    std::cout << "Enter your full name: ";
    std::getline(std::cin, full_name);
    std::cout << "Your full name is: " << full_name << std::endl;

    // Find
    std::cout << "\nFind\n-----------------" << std::endl; 
    s1 = "The secret word is Boo";
    std::string word;
    std::cout << "Enter the word to find: ";
    std::cin >> word;
    size_t position = s1.find(word);
    if (position != std::string::npos) // no position
        std::cout << "Found " << word << " at position: " << position << std::endl;
    else
        std::cout << "Sorry, " << word <<  " not found" << std::endl;

    return 0;
}