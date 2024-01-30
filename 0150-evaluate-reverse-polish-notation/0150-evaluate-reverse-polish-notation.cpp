class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i].compare("+")==0 || tokens[i].compare("-")==0 || tokens[i].compare("*")==0 || tokens[i].compare("/")==0 )
            {
                int n1,n2;
                if(s.size() >= 2)
                {
                    n1 = s.top();
                    s.pop();
                    n2 = s.top();
                    s.pop();
                    
                    if(tokens[i].compare("+")==0)
                    {
                        s.push(n1 + n2);
                    }
                    else if(tokens[i].compare("-")==0)
                    {
                        s.push(n2 - n1);
                    }
                    else if(tokens[i].compare("*")==0)
                    {
                        s.push(n1 * n2);
                    }
                    else
                    {
                        s.push(n2 / n1);
                    }
                }
                
            }
            else
            {
                int num = stoi(tokens[i]);
                s.push(num);
            }
        }
        return s.top();
    }
};