
bool isValidParenthesis(string expression) {
    unordered_set<char> parOpen = {'{', '(', '['};
    unordered_set<char> parClose = {'}', ')', ']'};
    stack<char> sk;
    unordered_map<char, char> match = {{'}', '{'}, {')', '('}, {']', '['}};
    for (char ch : expression) {
        if (parOpen.count(ch)) {
            sk.push(ch);
        } else if (parClose.count(ch)) {
            if (!sk.empty() && match[ch] == sk.top()) {
                sk.pop();
            } else {
                return false;
            }
        }
    }
    return sk.empty();
}
