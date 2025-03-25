#include <iostream>
#include <string>
#include <vector> // Used for storage of songs
#include <iomanip>

// For Playlist Shuffle
#include <algorithm>
#include <ctime>

// for playing songs
#include <chrono>
#include <thread>

using namespace std;
using namespace chrono;
using namespace std::this_thread;

class Song
{
public:
    string artist;
    string songName;
    float duration;
    string genre;
    Song(string artist, string songName, float duration, string genre);
};

Song::Song(string artist, string songName, float duration, string genre)
{
    this->artist = artist;
    this->songName = songName;
    this->duration = duration;
    this->genre = genre;
};

int main()
{
    int num;
    char userSelection;
    vector<Song> songList;
    string playlistName;

    cout << "\n";
    cout << "Enter a Name for Playlist\n";
    cout << "Playlist Name: ";
    getline(cin, playlistName);

    cout << "\n";
    cout << "Great Name!\n";
    cout << "Lets work on a couple of personalizations in " << playlistName << "'s Playlist\n";

    do
    {
        userSelection = 'N';

        cout << endl;
        cout << "1. Add song \n";
        cout << "2. Remove Song \n";
        cout << "3. Find Song \n";
        cout << "4. Shuffle Playlist\n";
        cout << "5. List All Songs Ordered in Playlist \n";
        cout << "\nEnter Selection (1-5): ";

        cin >> num;
        cin.ignore();

        // CASE COME

        // CASE 1 VARS
        string songArtistName;
        string songTitle;
        float songDuration;
        string genreName;

        // CASE 2 VARS & 3
        bool songNameFound = false;
        bool artistNameFound = false;
        int savedIndex_1;
        int savedIndex_2;

        // CASE 3 VARS

        switch (num)
        {
        case 1:
            cout << "\n";
            cout << "Adding Song\n";
            cout << "---------------------------\n";
            cout << "Enter Artists Name: ";
            getline(cin, songArtistName);
            cout << "Enter Song Name: ";
            getline(cin, songTitle);
            cout << "Enter Song Genre: ";
            getline(cin, genreName);
            cout << "Enter Song Duration Format(Minutes.seconds) ";
            cin >> songDuration;
            cin.ignore();
            songList.emplace_back(songArtistName, songTitle, songDuration, genreName);
            cout << "Song added successfully!\n";
            cout << "\n";
            break;

        case 2:
            if (songList.empty())
            {
                cout << "--------------------------------------\n";
                cout << "No songs found in the playlist to Remove\n";
                cout << "Make sure to Add songs\n";
                cout << "--------------------------------------\n";
                cout << "\n";
                break;
            }
            cout << "\n";
            cout << "Removing Song\n";
            cout << "---------------------------\n";

            cout << "Well Sometimes our music taste changes " << "\u2639\n";
            cout << "\n";
            /// Might implement robust searching algorithms later
            cout << "Enter Song Name to Delete (case-sensitive): ";
            getline(cin, songTitle);

            for (int i = 0; i < songList.size(); i++)
            {
                if (songTitle == songList.at(i).songName)
                {
                    songNameFound = true;
                    savedIndex_1 = i;
                }
            }

            cout << "Enter Artist's Full Name for Song to Delete(case-sensitive): ";
            getline(cin, songArtistName);

            for (int i = 0; i < songList.size(); i++)
            {
                if (songArtistName == songList.at(i).artist)
                {
                    artistNameFound = true;
                    savedIndex_2 = i;
                }
            }

            if (artistNameFound && songNameFound && savedIndex_1 == savedIndex_2)
            {
                songList.erase(songList.begin() + savedIndex_1);
                cout << "\n";
                cout << "Song is deleted from Playlist!\n";
                cout << "\n";
            }
            else
            {
                cout << "\n";
                cout << "--Song not Found--\n";
                cout << "--Retry and be case sensitive--\n";
                cout << "\n";
            }
            break;

        case 3:
            if (songList.empty())
            {
                cout << "--------------------------------------\n";
                cout << "Cannot search because songs found in the playlist.\n";
                cout << "--------------------------------------\n";
                cout << "\n";
                break;
            }
            cout << "\n";
            cout << "Finding Song\n";
            cout << "---------------------------\n";

            cout << "Enter Song Name to Find(case-sensitive): ";
            getline(cin, songTitle);

            for (int i = 0; i < songList.size(); i++)
            {
                if (songTitle == songList.at(i).songName)
                {
                    songNameFound = true;
                    savedIndex_1 = i;
                }
            }

            cout << "Enter Artist's Full Name for Song to Find(case-sensitive): ";
            getline(cin, songArtistName);

            for (int i = 0; i < songList.size(); i++)
            {
                if (songArtistName == songList.at(i).artist)
                {
                    artistNameFound = true;
                    savedIndex_2 = i;
                }
            }

            if (artistNameFound && songNameFound && savedIndex_1 == savedIndex_2)
            {
                cout << "\n";
                cout << "Song is Found in Playlist!\n";
                cout << "Displaying Song Information\n";
                cout << "--------------------------------------\n";

                cout << "Song Name: " << songList[savedIndex_1].songName << endl;
                cout << "Artist Name: " << songList[savedIndex_1].artist << endl;
                cout << "Duration Name: " << songList[savedIndex_1].duration << " minutes" << endl;
                cout << "Genre: " << songList[savedIndex_1].genre << endl;
                cout << "\n";
            }
            else
            {
                cout << "\n";
                cout << "--Song not Found--\n";
                cout << "--Retry and be case sensitive--\n";
                cout << "\n";
            }

            break;

        case 4:
            if (songList.empty())
            {
                cout << "--------------------------------------\n";
                cout << "No songs found in the playlist to shuffle.\n";
                cout << "--------------------------------------\n";
                cout << "\n";
                break;
            }

            srand(time(0));
            for (int i = songList.size() - 1; i > 0; i--)
            {
                int j = rand() % (i + 1);
                swap(songList[i], songList[j]);
            } // Fisher-Yates shuffle algorithm

            cout << "Playlist Shuffled!\n";
            cout << "\n";

            break;

        case 5:
            cout << "\n";

            if (songList.empty())
            {
                cout << "--------------------------------------\n";
                cout << "No songs found in the playlist.\n";
                cout << "--------------------------------------\n";
                cout << "\n";
                break;
            }
            for (int i = 0; i < songList.size(); i++)
            {
                cout << "--------------------------------------\n";
                cout << "SONG #" << i + 1 << "\n";
                cout << "Song Name: " << songList.at(i).songName << "\n";
                cout << "Artists Name: " << songList.at(i).artist << "\n";
                cout << "Song Duration: " << songList.at(i).duration << "\n";
            }
            cout << "--------------------------------------\n";
            cout << "End of playlist reached.\n";
            cout << "--------------------------------------\n";
            cout << "\n";
            break;

        default:
            break;
        }

        cout << "Would you like to continue making changes to the playlist? (Y/N): ";
        cin >> userSelection;
        userSelection = toupper(userSelection);
    } while (userSelection == 'Y');

    if (songList.empty()) // Check if the vector is empty
    {
        cout << "NO DATA AVAILABLE TO KEEP GOING\n";
        cout << "PROGRAM ENDED\n";
        return 0;
    }
    // PART 2 FOR PLAYING SONGS, SKIPPING SONGS
    // PART 2 FOR PLAYING SONGS, SKIPPING SONGS
    // PART 2 FOR PLAYING SONGS, SKIPPING SONGS
    int userNum;
    int seconds;
    char userSelects;

    /// CASE 1 VARS

    // CASE 2 VARS
    bool songNameFound_2 = false;
    bool artistNameFound_2 = false;
    int savedIndex_1_2;
    int savedIndex_2_2;
    string songTitle_2;
    string songArtistName_2;

    // CASE 3 VARS
    int totalMinutes;
    int totalSeconds;
    double totalDuration = 0;

    // CASE 4 VARS
    do
    {
        userSelects = 'N';

        cout << "\n";
        cout << "Playlist Menu\n";
        cout << "--------------------------------------\n";
        cout << "1. Play Playlist\n";
        cout << "2. Play Specific Song\n";
        cout << "3. Show total Duration of Playlist\n";
        cout << "4. Show All songs in the Playlist\n";
        cout << "\nEnter Selection (1-4): ";
        cin >> userNum;
        cin.ignore();
        switch (userNum)
        {
        case 1:
            cout << "\n";
            cout << "Playing.... " << playlistName << "'s Playlist\n";

            for (int i = 0; i < songList.size(); i++)
            {
                int totalSeconds = int(songList[i].duration * 60);
                cout << "--------------------------------------\n";
                cout << "SONG #" << i + 1 << "\n";
                cout << "Playing: 🎶 " << songList[i].songName << "\n";
                cout << "Artist Name: " << songList[i].artist << "\n";
                cout << "Song Duration: " << songList[i].duration << " minutes\n";

                for (int j = 0; j < totalSeconds; j++) // playing second by second
                {
                    this_thread::sleep_for(chrono::seconds(1)); // Wait for 1 second
                    cout << "\rPlaying: " << songList[i].songName << " - " << j + 1 << " seconds" << flush;
                }
                // adding pausing will mena requesting input from user every few seconds so I decided not to add it
                cout << "\nSong Finished: " << songList[i].songName << "\n";
                cout << "--------------------------------------\n";
            }

            break;

        case 2:
            cout << "\n";
            cout << "Finding Song in Playlist....\n";
            cout << "Enter Song Name to Find(case-sensitive): ";
            getline(cin, songTitle_2);

            for (int i = 0; i < songList.size(); i++)
            {
                if (songTitle_2 == songList.at(i).songName)
                {
                    songNameFound_2 = true;
                    savedIndex_1_2 = i;
                }
            }

            cout << "Enter Artist's Full Name for Song to Find(case-sensitive): ";
            getline(cin, songArtistName_2);

            for (int i = 0; i < songList.size(); i++)
            {
                if (songArtistName_2 == songList.at(i).artist)
                {
                    artistNameFound_2 = true;
                    savedIndex_2_2 = i;
                }
            }

            if (artistNameFound_2 && songNameFound_2 && savedIndex_1_2 == savedIndex_2_2)
            {

                int totalSeconds = int(songList[savedIndex_1_2].duration * 60);
                cout << "--------------------------------------\n";
                cout << "Playing: 🎶 " << songList[savedIndex_1_2].songName << "\n";
                cout << "Artist Name: " << songList[savedIndex_1_2].artist << "\n";
                cout << "Song Duration: " << songList[savedIndex_1_2].duration << " minutes\n";

                for (int j = 0; j < totalSeconds; j++) // playing second by second
                {
                    this_thread::sleep_for(chrono::seconds(1)); // Wait for 1 second
                    cout << "\rPlaying: " << songList[savedIndex_1_2].songName << " - " << j + 1 << " seconds" << flush;
                }
                // adding pausing will mean requesting input from user every few seconds so I decided not to add it
                cout << "\nSong Finished: " << songList[savedIndex_1_2].songName << "\n";
                cout << "--------------------------------------\n";
            }
            else
            {
                cout << "\n";
                cout << "--Song not Found--\n";
                cout << "--Retry and be case sensitive--\n";
                cout << "\n";
            }

            break;

        case 3:
            for (int i = 0; i < songList.size(); i++)
            {
                totalDuration += songList[i].duration;
            }

            totalMinutes = static_cast<int>(totalDuration);
            totalSeconds = static_cast<int>((totalDuration - totalMinutes) * 60);

            cout << "--------------------------------------\n";
            cout << "Total Playlist Duration: " << totalMinutes << " minutes and " << totalSeconds << " seconds\n";
            cout << "--------------------------------------\n";

            break;

        case 4:

            cout << "\n"
                 << playlistName << "'s songs\n";
            for (int i = 0; i < songList.size(); i++)
            {
                cout << "--------------------------------------\n";
                cout << "SONG #" << i + 1 << "\n";
                cout << "Song Name: " << songList.at(i).songName << "\n";
                cout << "Artists Name: " << songList.at(i).artist << "\n";
                cout << "Song Duration: " << songList.at(i).duration << "\n";
            }
            cout << "--------------------------------------\n";
            cout << "End of playlist reached.\n";
            cout << "--------------------------------------\n";
            cout << "\n";
            break;

        default:
            break;
        }

        /* Show Total Duration: Display the total duration of all songs in the playlist.
        Play Specific Song: Let the user choose and play a specific song from the playlist.
        */
        cout << "Would you like to go back to Playlist Menu? (Y/N): ";
        cin >> userSelects;
        userSelects = toupper(userSelects);
    } while (userSelects == 'Y');

    cout << "\nThanks for using the program\n";
    cout << "   *****   " << endl;
    cout << "  *     *  " << endl;
    cout << " *  O O  * " << endl;
    cout << " *   =   * " << endl;
    cout << " *  '-'  * " << endl;
    cout << "  *     *  " << endl;
    cout << "   *****   " << endl;

    return 0;
}
