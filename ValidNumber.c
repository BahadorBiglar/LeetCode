bool isNumber(char* s) {
    bool    started = false, finished = false, pointSeen = false, eSeen = false,
            numsAfterE = false, isValid=false, digitSeen = false, signSeen=false, signAfterESeen=false;
    
    for (int pos = 0; s[pos] != '\0'; pos++){
        switch(s[pos]){
            case '+' :
            case '-' :  if (finished)
                            return false;
                        if ((eSeen) && (numsAfterE))
                            return false;
                        if (started && !eSeen)
                            return false;
                        if ((started) && (eSeen) && (signAfterESeen))
                            return false;
                        
                        if (eSeen)
                            signAfterESeen = true;
                        else
                            signSeen=true;
                        started = true;
                        break;
            case ' ' :
            case '\t':  if (!started) continue;
                            else finished = true;
                        break;
            case '.':   if (finished)
                            return false;
                        if (pointSeen)
                            return false;
                        if (eSeen)
                            return false;
                        if ((!started) && (!pointSeen)){
                            started = true;
                        }
                        pointSeen = true;
                        break;
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':   if (finished)
                            return false;
                        if (eSeen)
                            numsAfterE=true;
                        started = true;
                        isValid = true;
                        digitSeen = true;
                        break;
            case 'e':
            case 'E':   if (finished)
                            return false;
                        if (!started)
                            return false;
                        if (eSeen)
                            return false;
                        if (!isValid)
                            return false;
                        eSeen=true;
                        isValid=false;
                        break;
            default : return false;
        }
    }
    return isValid;
}