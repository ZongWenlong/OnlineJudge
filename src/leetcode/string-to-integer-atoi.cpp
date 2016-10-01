class Solution {
public:
    int myAtoi(string str) {
        enum Status{
            START,BLANK,SIGN,NUM,END
        } status = START;
        
        long value = 0;
        int sign = 1;
        for(auto c : str){
            switch(status){
                case START:
                    if(c == '+'){
                        status = SIGN;
                    }
                    else if(c == '-'){
                        status = SIGN;
                        sign = -1;
                    }
                    else if(c >= '0' && c <= '9'){
                        status = NUM;
                        value = c - '0';
                    }
                    else if(c != ' '){
                        return 0;
                    }
                    break;
                case SIGN:
                    if(c >= '0' && c <= '9'){
                        status = NUM;
                        value = c - '0';
                    }
                    else{
                        return 0;
                    }
                    break;
                case NUM:
                    if(c >= '0' && c <= '9'){
                        value = value * 10 + (c - '0') ;
                        if(value * sign >= INT_MAX){
                            return INT_MAX;
                        }
                        else if(value * sign <= INT_MIN){
                            return INT_MIN;
                        }
                    }
                    else{
                        return (int)(sign * value);
                    }
                    break;
            }
        }
        return (int) (sign * value);
  
    }
};