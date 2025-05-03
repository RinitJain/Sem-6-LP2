#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string ask_question(const string& question) {
    string response;
    cout << question << " ";
    getline(cin, response);
    transform(response.begin(), response.end(), response.begin(), ::tolower);
    return response;
}

int main() {
    cout << "📁 Information Management Expert System\n\n";

    string importance = ask_question("Is the information important? (yes/no)");
    string usage = ask_question("Is the information frequently accessed? (yes/no)");
    string age = ask_question("Is the information older than 1 year? (yes/no)");
    string legal = ask_question("Is the information legally required to be retained? (yes/no)");

    // Decision rules
    if (importance == "yes" && usage == "yes" && legal == "yes") {
        cout << "\n🟢 Action: RETAIN the information in active storage.\n";
    } else if (importance == "yes" && usage == "no" && legal == "yes") {
        cout << "\n📦 Action: ARCHIVE the information for future reference.\n";
    } else if (importance == "no" && age == "yes" && legal == "no") {
        cout << "\n🗑️ Action: DELETE the information (no longer needed).\n";
    } else if (importance == "yes" && age == "no" && usage == "yes") {
        cout << "\n💾 Action: BACKUP the information regularly.\n";
    } else {
        cout << "\n⚠️ Action: REVIEW the information manually before taking action.\n";
    }

    return 0;
}
