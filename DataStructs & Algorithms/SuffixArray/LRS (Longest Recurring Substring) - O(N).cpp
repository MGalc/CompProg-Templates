// Use after using LCP.cpp

bool findLRS(int& largestv, int& stringindx, int& amount) {
    largestv = 0;
    stringindx = -1;
    amount = 0;

    int largestindx;
    for (int i = 0; i < LCP.size(); i++) {
        if (LCP[i] > largestv) {
            largestv = LCP[i];
            largestindx = i;
            stringindx = SA[i];
        }
    }

    if (largestv == 0)
        return false;

    amount = 1;
    int i = largestindx;
    while (i != LCP.size() && LCP[i] == largestv)
        amount++, i++;

    return true;
}
