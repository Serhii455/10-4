#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <iomanip>

using namespace std;

struct Car {
    string brand;
    double cost;
    double mileage;
};

void readDataFromFile(string filename, Car cars[], int& numCars) {
    ifstream inFile(filename);

    if (!inFile.is_open()) {
        cerr << "Error opening the file: " << filename << endl;
        // Використовуємо виняток або повертаємо код помилки
        throw runtime_error("Error opening the file");
    }

    numCars = 0;
    while (inFile >> cars[numCars].brand >> cars[numCars].cost >> cars[numCars].mileage) {
        numCars++;
    }

    inFile.close();
}

bool compareByBrand(const Car& car1, const Car& car2) {
    return car1.brand < car2.brand;
}

void sortCarsByBrand(Car cars[], int numCars) {
    sort(cars, cars + numCars, compareByBrand);
}

double calculateAverageMileage(const Car cars[], int numCars) {
    double totalMileage = 0.0;
    for (int i = 0; i < numCars; ++i) {
        totalMileage += cars[i].mileage;
    }

    return totalMileage / numCars;
}

int countUniqueBrands(const Car cars[], int numCars) {
    map<string, int> uniqueBrands;
    for (int i = 0; i < numCars; ++i) {
        uniqueBrands[cars[i].brand]++;
    }

    return uniqueBrands.size();
}

void writeSortedDataToFile(string outputFilename, const Car cars[], int numCars, double averageMileage, int uniqueBrandCount) {
    ofstream outFile(outputFilename);

    if (!outFile.is_open()) {
        cerr << "Error opening the file for writing: " << outputFilename << endl;
        throw runtime_error("Error opening the file for writing");
    }

    for (int i = 0; i < numCars; ++i) {
        outFile << cars[i].brand << " " << cars[i].cost << " " << cars[i].mileage;

        outFile << " " << fixed << setprecision(2) << averageMileage;

        outFile << endl;
    }

    outFile << "Unique Brands: " << uniqueBrandCount << endl;

    outFile.close();
}

int main() {
    string filename;
    const int maxCars = 100;
    Car cars[maxCars];
    int numCars;

    string outputFilename;

    int menuItem;
    do {
        cout << endl << endl << endl;
        cout << "Select an action: " << endl << endl;
        cout << " [1] - Read data from file" << endl;
        cout << " [2] - Sort cars by brand" << endl;
        cout << " [3] - Avarage mileage" << endl;
        cout << " [4] - Find count of incomplete brands" << endl;
        cout << " [5] - Write modified data to file" << endl;
        cout << " [0] - Exit" << endl << endl;
        cout << "Input value: "; cin >> menuItem;
        cout << endl << endl << endl;

        switch (menuItem)
        {
        case 1:
            cout << "Enter the filename: "; cin >> filename;
            readDataFromFile(filename, cars, numCars);
            break;
        case 2:
            sortCarsByBrand(cars, numCars);
            break;
        case 3:
            cout << "Average Mileage: " << calculateAverageMileage(cars, numCars) << endl;
            break;
        case 4:
            cout << "Unique Brands: " << countUniqueBrands(cars, numCars) << endl;
            break;
        case 5:
            cout << "Enter the filename: "; cin >> outputFilename;
            writeSortedDataToFile(outputFilename, cars, numCars, calculateAverageMileage(cars, numCars), countUniqueBrands(cars, numCars));
            break;
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Wrong input =(" << endl;
        }
    } while (menuItem != 0);

    return 0;
}