//Stores and displays movie data using structures and functions.

#include <iostream>
#include <string>
using namespace std;

// Structure to hold movie information
struct MovieData {
    string title;
    string director;
    int yearReleased;
};

// Function to create and return MovieData from user input
MovieData createMovieData() {
    MovieData movie;
    cout << "Enter movie title: ";
    getline(cin, movie.title);
    cout << "Enter director name: ";
    getline(cin, movie.director);
    cout << "Enter year of release: ";
    cin >> movie.yearReleased;
    cin.ignore();  // To consume leftover newline
    return movie;
}

// Function to display movie information
void displayMovieData(const MovieData& movie) {
    cout << "\n--- Movie Information ---" << endl;
    cout << "Title     : " << movie.title << endl;
    cout << "Director  : " << movie.director << endl;
    cout << "Year      : " << movie.yearReleased << endl;
    cout << "--------------------------\n" << endl;
}

int main() {
    cout << "Enter details for Movie 1:\n";
    MovieData movie1 = createMovieData();

    cout << "\nEnter details for Movie 2:\n";
    MovieData movie2 = createMovieData();

    displayMovieData(movie1);
    displayMovieData(movie2);

    return 0;
}
