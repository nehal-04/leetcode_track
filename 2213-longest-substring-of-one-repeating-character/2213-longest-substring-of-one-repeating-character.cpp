class Solution {
struct Node{
    char start_c;
    char end_c;

    int prefix;
    int suffix;

    int longest_len;
    int total_len;

    Node(char start_char , char end_char , int pre , int suf , int long_len , int total_l){
        start_c = start_char;
        end_c = end_char;
        prefix = pre;
        suffix = suf;
        longest_len = long_len;
        total_len = total_l;
    }

};
private:
    vector<Node*>seg; // {the char longest , its start , its end }
    void builder(int idx , int low , int high , string&s){
        if(low == high){
            seg[idx] = new Node(s[low] , s[low] , 1 ,1 ,1 , 1);
            return;
        }
        
        int mid = low + (high - low) /2;
        builder(2*idx + 1 , low , mid , s);
        builder(2*idx + 2 , mid+1 , high , s);

        char start_1 = seg[2*idx + 1]->start_c;
        char start_2 = seg[2*idx + 2] ->start_c;

        char last_1 = seg[2*idx + 1] ->end_c;
        char last_2  = seg[2*idx + 2] ->end_c;


        // required only actually last_1 and start_2 as they can combine so tak suffix of first and prefix of second and keep

        int suffix_one = seg[2*idx + 1] ->suffix;
        int prefix_two = seg[2*idx + 2]->prefix;

        int prefix_one = seg[2*idx + 1] -> prefix;
        int suffix_two = seg[2*idx + 2] -> suffix;


        int size1 = seg[2*idx + 1] -> total_len;
        int size2 = seg[2*idx + 2] -> total_len;

        int longest = max(seg[2*idx + 1]->longest_len , seg[2*idx + 2] ->longest_len); 

        if(start_2 == last_1){
            int combined_len = suffix_one + prefix_two;
            
            //initial values
            int suffix_full = seg[2*idx + 2] ->suffix;
            int prefix_full = seg[2*idx + 1] -> prefix;

            if(prefix_full == size1) prefix_full = combined_len;
            if(suffix_full == size2) suffix_full = combined_len;

            int new_l = max(longest , combined_len);

            seg[idx]= new Node(start_1 , last_2 , prefix_full , suffix_full , new_l , size1+size2);

        }
        else {
            seg[idx] = new Node(start_1 , last_2 , prefix_one , suffix_two , longest , seg[2*idx + 1] -> total_len + seg[2*idx + 2] -> total_len); 
        }
        return;
    }

    void answer_per_query(int idx , int low , int high , int index , char new_c){
        if(low == high){
            seg[idx] = new Node(new_c , new_c , 1 ,1 , 1 ,1);
            return;
        }

        int mid = low + (high - low)/2;
        if(index <= mid) answer_per_query(2*idx+1 ,low,mid,index,new_c);
        else answer_per_query(2*idx + 2 , mid+1 , high , index , new_c);

        char start_1 = seg[2*idx + 1]->start_c;
        char start_2 = seg[2*idx + 2] ->start_c;

        char last_1 = seg[2*idx + 1] ->end_c;
        char last_2  = seg[2*idx + 2] ->end_c;


        // required only actually last_1 and start_2 as they can combine so tak suffix of first and prefix of second and keep

        int suffix_one = seg[2*idx + 1] ->suffix;
        int prefix_two = seg[2*idx + 2]->prefix;


        int prefix_one = seg[2*idx + 1] -> prefix;
        int suffix_two = seg[2*idx + 2] -> suffix;


        int size1 = seg[2*idx + 1] -> total_len;
        int size2 = seg[2*idx + 2] -> total_len;

        int longest = max(seg[2*idx + 1]->longest_len , seg[2*idx + 2] ->longest_len); 

        if(start_2 == last_1){
            int combined_len = suffix_one + prefix_two;
            
            //initial values
            int suffix_full = seg[2*idx + 2] ->suffix;
            int prefix_full = seg[2*idx + 1] -> prefix;

            if(prefix_full == size1) prefix_full = combined_len;
            if(suffix_full == size2) suffix_full = combined_len;

            int new_l = max(longest , combined_len);

            seg[idx]= new Node(start_1 , last_2 , prefix_full , suffix_full , new_l , size1+size2);

        }
        else {
            seg[idx] = new Node(start_1 , last_2 , prefix_one , suffix_two , longest , seg[2*idx + 1] -> total_len + seg[2*idx + 2] -> total_len); 
        }
        return;
    }
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        
        int n1 = s.size();

        seg.resize(4*n1);
        // informayion needed , longest in seequnce , start and end posn 

        builder(0,0,n1-1,s);
        vector<int>ans;
        for(int i = 0; i < queryIndices.size(); i++) {

            int index = queryIndices[i];
            char c = queryCharacters[i];

            answer_per_query(0,0, n1 - 1, index,c);

            ans.push_back(seg[0]->longest_len);
        }
        return ans;
    }

};