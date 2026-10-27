
#include "BrowserHistory.h"

#include <algorithm>
#include <cctype>
#include <iostream>

BrowserHistory::BrowserHistory()
    : head(nullptr), tail(nullptr), current(nullptr), size(0) {}

BrowserHistory::~BrowserHistory() {
    clearHistory();
}

bool BrowserHistory::isEmpty() const {
    return current == nullptr;
}

void BrowserHistory::deleteForwardHistory() {
    if (current == nullptr) {
        return;
    }

    HistoryNode* temp = current->next;
    current->next = nullptr;
    tail = current;

    while (temp != nullptr) {
        HistoryNode* nextNode = temp->next;
        delete temp;
        temp = nextNode;
        --size;
    }
}

void BrowserHistory::visit(const std::string& url) {
    if (url.empty()) {
        std::cout << "URL cannot be empty.\n";
        return;
    }

    // Visiting a new page discards forward history.
    if (current != nullptr) {
        deleteForwardHistory();
    }

    HistoryNode* newPage = new HistoryNode(url);

    if (current == nullptr) {
        head = tail = current = newPage;
    } else {
        current->next = newPage;
        newPage->prev = current;
        current = tail = newPage;
    }

    ++size;
    std::cout << "Visited: " << url << '\n';
}

void BrowserHistory::goBack() {
    if (current == nullptr || current->prev == nullptr) {
        std::cout << "No previous page available.\n";
        return;
    }

    current = current->prev;
    showCurrentPage();
}

void BrowserHistory::goForward() {
    if (current == nullptr || current->next == nullptr) {
        std::cout << "No next page available.\n";
        return;
    }

    current = current->next;
    showCurrentPage();
}

void BrowserHistory::showCurrentPage() const {
    if (current == nullptr) {
        std::cout << "No page is currently open.\n";
        return;
    }

    std::cout << "Current page: " << current->url << '\n';
}

void BrowserHistory::showHistory() const {
    if (head == nullptr) {
        std::cout << "Browsing history is empty.\n";
        return;
    }

    std::cout << "\n--- Browsing History ---\n";

    HistoryNode* temp = head;
    int position = 1;

    while (temp != nullptr) {
        std::cout << position++ << ". " << temp->url;

        if (temp == current) {
            std::cout << "  [CURRENT]";
        }

        std::cout << '\n';
        temp = temp->next;
    }

    std::cout << "Total pages: " << size << '\n';
}

void BrowserHistory::searchHistory(
    const std::string& keyword) const {

    if (keyword.empty()) {
        std::cout << "Search keyword cannot be empty.\n";
        return;
    }

    auto toLower = [](std::string text) {
        std::transform(text.begin(), text.end(), text.begin(),
            [](unsigned char ch) {
                return static_cast<char>(std::tolower(ch));
            });
        return text;
    };

    const std::string target = toLower(keyword);
    HistoryNode* temp = head;
    bool found = false;

    while (temp != nullptr) {
        if (toLower(temp->url).find(target) != std::string::npos) {
            std::cout << temp->url;

            if (temp == current) {
                std::cout << "  [CURRENT]";
            }

            std::cout << '\n';
            found = true;
        }

        temp = temp->next;
    }

    if (!found) {
        std::cout << "No matching URLs found.\n";
    }
}

void BrowserHistory::clearHistory() {
    HistoryNode* temp = head;

    while (temp != nullptr) {
        HistoryNode* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    head = tail = current = nullptr;
    size = 0;
}
