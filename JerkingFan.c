#include <iostream>

using namespace std;

void main()
{
    int i = 0;
    int flag[30000];
    int depth = 0;
    char arr[30000];
    char code[30000];
    memset(arr, 0, sizeof(arr));
    memset(flag, 0, sizeof(flag));

    cin >> code;

    for (int j = 0; code[j] != '\0'; j++) {
        switch (code[j])
        {
        case '>':
            i++;
            break;

        case '<':
            i--;
            break;

        case '+':
            arr[i]++;
            break;

        case '-':
            arr[i]--;
            break;

        case '.':
            cout << (char)arr[i];
            break;

        case ',':
            cin >> arr[i];
            break;

        case '[':
            if (arr[i] == 0) {
                int bracket_nesting = 1;
                while (bracket_nesting != 0) {
                    j++;
                    if (code[j] == '[') bracket_nesting++;
                    if (code[j] == ']') bracket_nesting--;
                }
            }
            else {
                flag[depth] = j;
                depth++;
            }
            break;

        case ']':
            if (arr[i] != 0) {
                j = flag[depth - 1];
            }
            else {
                depth--;
            }
            break;
        }
    }

}

