#ifndef CARDDATABASE_H
#define CARDDATABASE_H

class CardDatabase {
public:
    CardDatabase();
    ~CardDatabase();
    void addCard(const std::string& card);
    void removeCard(const std::string& card);
    bool findCard(const std::string& card) const;
private:
    std::vector<std::string> cards;
};

#endif // CARDDATABASE_H
