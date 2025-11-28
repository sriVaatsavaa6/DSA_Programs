#include <stdio.h>

char STR[100], PAT[100], REP[100], ANS[100];

// Function to read three strings from user
void read() {
    printf("Enter MAIN string: ");
    fgets(STR, sizeof(STR), stdin);
    
    printf("Enter PATTERN string to find: ");
    fgets(PAT, sizeof(PAT), stdin);
    
    printf("Enter REPLACE string: ");
    fgets(REP, sizeof(REP), stdin);
}

// Function to replace all occurrences of PAT with REP in STR
void replace() {
    int i = 0, j = 0, k = 0, flag = 0;
    
    while (STR[i] != '\0') {
        int match = 1;  // Assume pattern matches
        int tempI = i;
        int tempK = 0;
        
        // Check if PAT matches at current position in STR
        while (PAT[tempK] != '\0') {
            if (STR[tempI] != PAT[tempK]) {
                match = 0;  // Pattern doesn't match
                break;
            }
            tempI++;
            tempK++;
        }
        
        // If pattern found, copy REP to ANS
        if (match == 1) {
            int repIdx = 0;
            while (REP[repIdx] != '\0') {
                ANS[j] = REP[repIdx];
                j++;
                repIdx++;
            }
            i = tempI;  // Move past the matched pattern
            flag = 1;   // Mark that pattern was found
        }
        // If pattern not found, copy character from STR to ANS
        else {
            ANS[j] = STR[i];
            j++;
            i++;
        }
    }
    
    ANS[j] = '\0';  // Null terminate the result string
    
    // Display result
    if (flag == 0) {
        printf("\nPattern NOT found!!!\n");
    } else {
        printf("\nThe RESULTANT string is:\n%s\n", ANS);
    }
}

int main() {
    read();      // Read three strings
    replace();   // Replace pattern with new string
    return 0;
}
