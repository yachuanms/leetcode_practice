#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool checkInclusion(char* s1, char* s2){

    int freq1[26] = {0};
    int freq2[26] = {0};
    int len1 = strlen(s1);
    

    if(len2<len1){
        return false;
    }

    for(int i = 0; s1[i]; i++){
        freq1[s1[i]-'a']++;
        freq2[s2[i]-'a']++;
    }

    if(memcmp(freq1, freq2, 26*sizeof(int)) == 0){
        return true;
    }

    for(int right = len1; s2[right]; right++){
        freq2[s2[right-len1]-'a']--;
        freq2[s2[right]-'a']++;
        
        if(memcmp(freq1, freq2, 26*sizeof(int)) == 0){
            return true;
        }    
        
    }

    return false;
    
}

int main() {
    printf("Test 1: %d\n", checkInclusion("ab", "eidbaooo")); // 預期 1 (true, "ba")
    printf("Test 2: %d\n", checkInclusion("ab", "eidboaoo")); // 預期 0 (false)
    printf("Test 3: %d\n", checkInclusion("adc", "dcda"));    // 預期 1 (true, "dcd"?? actually "cda" is permutation)
    printf("Test 4: %d\n", checkInclusion("a", "a"));         // 預期 1
    printf("Test 5: %d\n", checkInclusion("abc", "bbbca"));   // 預期 1 ("bca")
    printf("Test 6: %d\n", checkInclusion("ky", "ainwkckifykxlribaypk"));// 預期 1
    return 0;
}
