// class Solution {
// public:
//     int numUniqueEmails(vector<string>& emails) {
//         map<string,int>mp;
// // ["a@e+c.com", "a@e+c+f.com"]

//         for(int i=0;i<emails.size();i++){
//             string z="";
//             string y=emails[i];
//             bool flag=false;
//             for(int j=0;j<y.size();j++){
//                 if(y[j]=='+'&&flag==false)
//                 {
//                     while(y[j]!='@'&&j<y.size())j++;
                
//                 }
//                 if(j==y.size()) break;
//                 else if(y[j]=='@') {
//                     flag=true;
//                     z+=y[j];
//                 }
//                 else if(y[j]!='.'&&flag==false){
//                     z+=y[j];
//                 }
//                 else if(flag==true&&y[j]=='.') z+=y[j];
//                 else if(flag==true&&y[j]!='.'&&y[j]!='+') z+=y[j];
//                 else continue;
//             }
//             cout<<z<<endl;
//             mp[z]++;
//         }
//         return mp.size();
//     }
// };
class Solution {
public: //TC and SC is O(N*L) where L is length of the word 
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> st;

        for (string email : emails) {

            string local = "";
            string domain = "";

            int i = 0;

            // build local name
            while (email[i] != '@') {
                if (email[i] == '+') {
                    // skip till '@'
                    while (email[i] != '@') i++;
                    break;
                }
                if (email[i] != '.') {
                    local += email[i];
                }
                i++;
            }

            // build domain name
            while (i < email.size()) {
                domain += email[i];
                i++;
            }

            st.insert(local + domain);
        }

        return st.size();
    }
};
