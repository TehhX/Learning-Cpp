#include <iostream>
#include <array>

// Base class
class Media {
protected:
    const int id;
    const std::string title;

public:
    Media(const int id, const std::string_view title)
    : id { id }, title { title } {}

    virtual std::string toString() const {
        return "ID: " + std::to_string(id) + ", Title: " + title;
    }

    // Base virtual function, declared with virtual keyword.
    virtual void printType() const { std::cout << "Media\n"; }
};

class Movie : public Media {
private:
    const float runtime;
    const std::string format;

public:
    Movie(const int id, const std::string_view title, const float runtime, const std::string format)
    : Media { id, title }, runtime { runtime }, format { format } {}

    virtual std::string toString() const override {
        return Media::toString() + ", Runtime: " + std::to_string(runtime) + ", Format: " + format;
    }

    // Derived virtual function, ALSO declared with virtual keyword.
    virtual void printType() const override { std::cout << "Movie\n"; };
};

class Book : public Media {
private:
    const int pageCount;
    const std::string author;

public:
    Book(const int id, const std::string_view title, const int pageCount, const std::string author)
    : Media { id, title }, pageCount { pageCount }, author { author } {}

    virtual std::string toString() const override {
        return Media::toString() + ", Page Count: " + std::to_string(pageCount) + ", Author: " + author;
    }

    virtual void printType() const override { std::cout << "Book.\n"; }
};

class Album : public Media {
private:
    const int songCount;
    const float avgSongDuration;

public:
    Album(const int id, const std::string_view title, const int songCount, const float avgSongDuration)
    : Media { id, title }, songCount { songCount }, avgSongDuration { avgSongDuration } {}

    virtual std::string toString() const override {
        return Media::toString() + ", Song Count: " + std::to_string(songCount) +
            ", Average Song Duration: " + std::to_string(avgSongDuration);
    }

    virtual void printType() const override { std::cout << "Album.\n"; }
};

int main() {
    Media baseMedia   { 363, "N/A" };
    Movie ncfomMovie  { 545, "No Country for Old Men", 2.01f, "BluRay" };
    Book  mmBook      { 934, "Mr. Mercedes", 436, "Stephen King" };
    Album tdsotmAlbum { 849, "The Dark Side of the Moon", 10, 4.315f };

    std::array<std::reference_wrapper<Media>, 4> mediaArr { baseMedia, ncfomMovie, mmBook, tdsotmAlbum };

    for (const auto& mediaRW : mediaArr) {
        Media& mediaR { mediaRW.get() }; // Dealing with the reference wrappers

        mediaR.printType();
        std::cout << mediaR.toString() << "\n\n";
    }

    return 0;
}