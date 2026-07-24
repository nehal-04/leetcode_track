class Solution {
public:
    int compress(vector<char>& chars) {

        char curchar=chars[0];
        int curc=1;
        int i=1;
        int ptr=0;
        while(i<chars.size()){
            if(chars[i] == curchar) curc++;
            else{
                chars[ptr]=curchar;
                if(curc>1){
                    string cnt = to_string(curc);
                    for(char c: cnt){
                        ptr++;
                        chars[ptr] = c;
                    }
                }
                curchar=chars[i];
                curc=1;
                ptr++;
            }
            i++;
        }
        chars[ptr]=curchar;
        if(curc>1){
            string cnt = to_string(curc);
            for(char c: cnt){
                ptr++;
                chars[ptr] = c;
            }
            
        }

        chars.resize(ptr+1);

        return chars.size();


        
    }
};