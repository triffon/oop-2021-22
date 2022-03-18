#include <iostream>
#include <cstring>
#include <cassert>

const unsigned int MAX_MINUTES_AND_SECONDS = 60;
const std::size_t INITIAL_CAPACITY = 2;
const std::size_t INCREASE_STEP = 2;

struct Duration
{
    unsigned int minutes;
    unsigned int seconds;

    Duration() : Duration(0, 0) {}

    Duration(unsigned int minutes, unsigned int seconds)
    {
        this->minutes = minutes;
        this->seconds = seconds;
    }

    bool isValid() const
    {
        return this->minutes < MAX_MINUTES_AND_SECONDS && 
               this->seconds < MAX_MINUTES_AND_SECONDS;
    }

    void print() const
    {
        std::cout << this->minutes << ":" << this->seconds << std::endl;
    }
};

class Song
{
private:
    char* name;
    char* genre;
    Duration duration;

    void copyString(char*& destination, const char* source)
    {
        destination = new (std::nothrow) char[strlen(source) + 1];
        if (!destination)
        {
            std::cout << "Memory problem!" << std::endl;
            return;
        }

        strcpy(destination, source);
    }

    void deallocate()
    {
        delete[] this->name;
        delete[] this->genre;
    }

    void copy(const Song& other)
    {
        assert(other.name != nullptr);
        assert(other.genre != nullptr);
        assert(other.duration.isValid());

        this->copyString(this->name, other.name);
        this->copyString(this->genre, other.genre);
        this->duration = other.duration;
    }

public:
    Song()
    {
        this->name = nullptr;
        this->genre = nullptr;
    }

    Song(const char* name, const char* genre, const Duration& duration) : Song()
    {
        this->setName(name);
        this->setGenre(genre);
        this->setDuration(duration);
    }

    Song(const Song& other)
    {
        this->copy(other);
    }

    Song& operator = (const Song& other)
    {
        if (this != &other)
        {
            this->deallocate();
            this->copy(other);
        }

        return *this;
    }

    void setName(const char* name)
    {
        assert(name != nullptr);

        delete[] this->name;
        this->copyString(this->name, name);
    }

    void setGenre(const char* genre)
    {
        assert(name != nullptr);

        delete[] this->genre;
        this->copyString(this->genre, genre);
    }

    void setDuration(const Duration& duration)
    {
        this->duration = duration;
    }

    const char* getName() const
    {
        return this->name;
    }

    const char* getGenre() const
    {
        return this->genre;
    }

    Duration getDuration() const
    {
        return this->duration;
    }

    void print() const
    {
        std::cout << "Name: " << this->name << std::endl;
        std::cout << "Duration: ";
        this->duration.print();
        std::cout << "Genre: " << this->genre << std::endl;
    }

    ~Song()
    {
        this->deallocate();
    }
};

class Playlist
{
private:
    Song* songs;
    std::size_t size;
    std::size_t capacity;

    void copy(const Playlist& other)
    {
        this->songs = new (std::nothrow) Song[other.capacity];
        if (!this->songs)
        {
            std::cout << "Memory problem!" << std::endl;
            return;
        }

        for (std::size_t i = 0; i < other.size; ++i)
        {
            this->songs[i] = other.songs[i];
        }

        this->capacity = other.capacity;
        this->size = other.size;
    }

    void deallocate()
    {
        delete[] this->songs;
    }

    void resize()
    {
        Song* newSongs = new (std::nothrow) Song[this->capacity * INCREASE_STEP];
        if (!newSongs)
        {
            std::cout << "Memory problem!" << std::endl;
            return;
        }

        for (std::size_t i = 0; i < this->size; ++i)
        {
            newSongs[i] = this->songs[i];
        }

        this->deallocate();
        this->songs = newSongs;
        this->capacity *= INCREASE_STEP;
    }

    /**
     * @brief A method for getting the index of a song
     * 
     * @param songName the song's name we are checking
     * @return the index of the song if it is contained
     * @return -1 if the song is not contained
     */
    int getSongIndex(const char* songName)
    {
        assert(songName != nullptr);

        for(std::size_t i = 0; i < this->size; ++i)
        {
            if (strcmp(songName, this->songs[i].getName()) == 0)
            {
                return i;
            }
        }

        return -1;
    }

public:
    Playlist()
    {
        this->songs = new (std::nothrow) Song[INITIAL_CAPACITY];
        if (!this->songs)
        {
            std::cout << "Memory problem!" << std::endl;
            return;
        }

        this->capacity = INITIAL_CAPACITY;
        this->size = 0;
    }

    Playlist(const Playlist& other)
    {
        this->copy(other);
    }

    Playlist& operator = (const Playlist& other)
    {
        if (this != &other)
        {
            this->deallocate();
            this->copy(other);
        }

        return *this;
    }

    ~Playlist()
    {
        this->deallocate();
    }

    /**
     * @brief A method for adding a song to the playlist
     * @details The song should be added to the playlist only if 
     * there isn't a song with the same name
     * 
     * @param songToAdd the song that should be added
     */
    void addSong(const Song& songToAdd)
    {
        if (this->getSongIndex(songToAdd.getName()) == -1)
        {
            if (this->size == this->capacity)
            {
                this->resize();
            }
            this->songs[this->size++] = songToAdd;
        }
    }

    /**
     * @brief A method for removing a song from the playlist
     * 
     * @param songName the song's name we are removing
     * @return true if the removal is successfull
     * @return false if the removal is not successfull
     */
    bool removeSong(const char* songName)
    {
        int songIndex = this->getSongIndex(songName);

        if (songIndex == -1)
        {
            return false;
        }

        std::swap(this->songs[songIndex], this->songs[this->size - 1]);
        --this->size;

        return true;
    }

    /**
     * @brief A method for printing information about the playlist
     * 
     */
    void printPlaylistInfo()
    {
        std::cout << "SIZE: " << this->size << std::endl;
        std::cout << "CAPACITY: " << this->capacity << std::endl;
        for (std::size_t i = 0; i < this->size; ++i)
        {
            std::cout << "SONG #" << i+1 << std::endl;
            this->songs[i].print();
        }
    }
};


int main()
{
    Song song1("Can't let you go", "Rock", Duration(4, 17));
    Song song2("Nqkakva greshna", "nz", Duration(0, 0));
    Song song3("Da ne pitat", "Rap", Duration(3, 20));
    Song song4("Vodka s uteha", "Pop-folk", Duration(4, 7));
    Song song5("Senorita", "Pop", Duration(3, 25));

    Playlist mishMash;
    mishMash.addSong(song1);
    mishMash.addSong(song2);
    mishMash.addSong(song3);
    mishMash.addSong(song4);
    mishMash.addSong(song5);

    mishMash.printPlaylistInfo();

    Playlist copyWithoutGreshki;
    copyWithoutGreshki = mishMash;
    copyWithoutGreshki.removeSong("Nqkakva greshna");
    copyWithoutGreshki.printPlaylistInfo();

    Playlist onlyOneSong;
    onlyOneSong.addSong(song1);
    onlyOneSong.removeSong("Can't let you go");
    onlyOneSong.printPlaylistInfo();

    Playlist emptyPlaylist;
    std::cout << std::boolalpha << emptyPlaylist.removeSong("neshto") << std::endl;

    return 0;
}