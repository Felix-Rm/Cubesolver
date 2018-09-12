string color(int i){

    switch (i)
    {
        case red:
            return "\033[31;41m";
        case green:
            return "\033[32;42m";
        case yellow:
            return "\033[93;103m";
        case blue:
            return "\033[34;44m";
        case white:
            return "\033[97;107m";
        case orange:
            return "\033[33;43m";

        case dummy1:
            return "\033[31;105m";
        case dummy2:
            return "\033[32;105m";
        case dummy3:
            return "\033[92;105m";

        default:
            return "\033[90;100m";
            break;
    }
}


void drawCube(tile cube[3][3][3]){
    int printMap[12][9];

    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 9; j++){
            printMap[i][j] = -1;
        }
    }

    for(int i = 0; i < 9; i++){
        printMap[1 * 3 + (0+int(i%3))][0 * 3 + (2-int(i/3))] = cube[int(i/3)][0][int(i%3)].z;//orange
        printMap[1 * 3 + (0+int(i%3))][2 * 3 + (0+int(i/3))] = cube[int(i/3)][2][int(i%3)].z;//red

        printMap[1 * 3 + (0+int(i%3))][1 * 3 + (0+int(i/3))] = cube[0][int(i/3)][int(i%3)].y;//white
        printMap[3 * 3 + (2-int(i%3))][1 * 3 + (0+int(i/3))] = cube[2][int(i/3)][int(i%3)].y;//yellow

        printMap[0 * 3 + (2-int(i%3))][1 * 3 + (0+int(i/3))] = cube[int(i%3)][int(i/3)][0].x;//green
        printMap[2 * 3 + (0+int(i%3))][1 * 3 + (0+int(i/3))] = cube[int(i%3)][int(i/3)][2].x;//blue
    }

    for(int j = 0; j < 9; j++){
        for(int i = 0; i < 12; i++){
            cout << color(printMap[i][j]) << "++" << "\033[m";
        }
        cout << '\n';
    }

    cout << "------------------------" << '\n';

    usleep(vizualization_delay);
}
