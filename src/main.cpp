
#include "BrowserHistory.h"

#include <iostream>
#include <limits>
#include <string>

int main() {
    BrowserHistory browser;
    int choice = -1;

    do {
        std::cout << "\n====== BROWSER HISTORY SIMULATOR ======\n";
        std::cout << "1. Visit a new URL\n";
        std::cout << "2. Go Back\n";
        std::cout << "3. Go Forward\n";
        std::cout << "4. Show Current Page\n";
        std::cout << "5. Show Browsing History\n";
        std::cout << "6. Search History\n";
        std::cout << "7. Clear History\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter choice: ";

        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Enter a number.\n";
            std::cin.clear();
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(), '\n');

        std::string url;
        std::string keyword;

        switch (choice) {
            case 1:
                std::cout << "Enter URL: ";
                std::getline(std::cin, url);
                browser.visit(url);
                break;

            case 2:
                browser.goBack();
                break;

            case 3:
                browser.goForward();
                break;

            case 4:
                browser.showCurrentPage();
                break;

            case 5:
                browser.showHistory();
                break;

            case 6:
                std::cout << "Enter URL keyword: ";
                std::getline(std::cin, keyword);
                browser.searchHistory(keyword);
                break;

            case 7:
                browser.clearHistory();
                std::cout << "Browsing history cleared.\n";
                break;

            case 0:
                std::cout << "Exiting browser simulator.\n";
                break;

            default:
                std::cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
