#include <iostream>
#include <fstream>

using namespace std;

// Function to read a PGM file into a static 256x256 int array
void readPGM(const string& filename, int image[256][256]) {
	ifstream file(filename, ios::binary);

	if (file.is_open()) {
		string magicNumber;
		int width, height, maxGrayValue;

		file >> magicNumber >> width >> height >> maxGrayValue;

		if (magicNumber == "P5" && width == 256 && height == 256 && maxGrayValue == 255) {
			file.get(); // Read the newline character after max gray value

			for (int i = 0; i < height; ++i) {
				for (int j = 0; j < width; ++j) {
					unsigned char pixelValue;
					file.read(reinterpret_cast<char*>(&pixelValue), 1);
					image[i][j] = static_cast<int>(pixelValue);
				}
			}

			file.close();
		}
		else {
			cerr << "Invalid PGM format or image dimensions." << endl;
		}
	}
	else {
		cerr << "Unable to open the file: " << filename << endl;
	}
}

// Function to save the modified image back to a PGM file
void savePGM(const string& filename, const int image[256][256]) {
	ofstream file(filename, ios::binary);

	if (file.is_open()) {
		file << "P5\n256 256\n255\n";

		for (int i = 0; i < 256; ++i) {
			for (int j = 0; j < 256; ++j) {
				unsigned char pixelValue = static_cast<unsigned char>(image[i][j]);
				file.write(reinterpret_cast<const char*>(&pixelValue), 1);
			}
		}

		file.close();
	}
	else {
		cerr << "Failed to save the file." << endl;
	}
}

int main() {
	int image[256][256];
	int tempimage[256][256];
	const int imageSize = 256;
	// Declare required variables
	int tempimage2[256][256];
	readPGM("cat256.pgm", image);


	int choice;
	do {
		cout << "Menu:\n1. Reload PGM File\n2. Invert the image\n3. Blur the image\n4. Horizontal Edge Detection\n5. Vertical Edge Detection\n6. Terminate\n7. Invert image orientation (Bonus Task)\n8. Total edge detection (Bonus Task)\n9. Sharpen the image (Bonus Task)" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			readPGM("cat256.pgm", image); // Reload the PGM file
			break;
		case 2:
			// Enter the code for inverting the image here (For inverting orientation task 7 is performed).
			for (int i = 0; i < 256; i++)
			{
				for (int k = 0; k < 256; k++)
				{
					tempimage[i][k] = image[i][k];
				}
			}
			for (int i = 0; i < 256; i++)
			{
				for (int j = 0; j < 256; j++)
				{
					tempimage[i][j] = 255 - tempimage[i][j];
				}
			}
			for (int i = 0; i < 256; i++)
			{
				for (int k = 0; k < 256; k++)
				{
					image[i][k] = tempimage[i][k];
				}
			}
			savePGM("cat256_out.pgm", image);
			break;
		case 3:
			// Enter the code for blurring the image here (Applied 2 times because the blur was not strong enough on 1 iteration.)
			for (int i = 0; i < 256; i++)
			{
				for (int k = 0; k < 256; k++)
				{
					tempimage[i][k] = image[i][k];
				}
			}
			for (int i = 0; i < 254; i++)
			{
				for (int j = 0; j < 254; j++)
				{
					int ch1, ch2, ch3, final;
					ch1 = image[i][j] * 1 / 16 + image[i][j + 1] * 1 / 8 + image[i][j + 2] * 1 / 16;
					ch2 = image[i + 1][j] * 1 / 8 + image[i + 1][j + 1] * 1 / 4 + image[i + 1][j + 2] * 1 / 8;
					ch3 = image[i + 2][j] * 1 / 16 + image[i + 2][j + 1] * 1 / 8 + image[i + 2][j + 2] * 1 / 16;
					final = (ch1 + ch3 + ch2);
					if (final < 0)
					{
						final = 0;
					}
					else if (final > 255)
					{
						final = 255;
					}
					tempimage[i + 1][j + 1] = final;
				}
			}
			for (int i = 0; i < 256; i++)
			{
				for (int k = 0; k < 256; k++)
				{
					image[i][k] = tempimage[i][k];
				}
			}

			for (int i = 0; i < 256; i++)
			{
				for (int k = 0; k < 256; k++)
				{
					tempimage[i][k] = image[i][k];
				}
			}
			for (int i = 0; i < 254; i++)
			{
				for (int j = 0; j < 254; j++)
				{
					int ch1, ch2, ch3, final;
					ch1 = image[i][j] * 1 / 16 + image[i][j + 1] * 1 / 8 + image[i][j + 2] * 1 / 16;
					ch2 = image[i + 1][j] * 1 / 8 + image[i + 1][j + 1] * 1 / 4 + image[i + 1][j + 2] * 1 / 8;
					ch3 = image[i + 2][j] * 1 / 16 + image[i + 2][j + 1] * 1 / 8 + image[i + 2][j + 2] * 1 / 16;
					final = (ch1 + ch3 + ch2);
					if (final < 0)
					{
						final = 0;
					}
					else if (final > 255)
					{
						final = 255;
					}
					tempimage[i + 1][j + 1] = final;
				}
			}
			for (int i = 0; i < 256; i++)
			{
				for (int k = 0; k < 256; k++)
				{
					image[i][k] = tempimage[i][k];
				}
			}
			savePGM("cat256_out.pgm", image);
			break;
		case 4:
			// Enter the code for horizontal edge detection here
			for (int i = 0; i < 256; i++)
			{
				for (int k = 0; k < 256; k++)
				{
					tempimage[i][k] = image[i][k];
				}
			}
			for (int i = 0; i < 254; i++)
			{
				for (int j = 0; j < 254; j++)
				{
					int ch1, ch2, final;
					ch1 = image[i][j] * -1 + image[i][j + 1] * -2 + image[i][j + 2] * -1;
					ch2 = image[i + 2][j] * 1 + image[i + 2][j + 1] * 2 + image[i + 2][j + 2] * 1;
					final = (ch1 + ch2);
					if (final < 0)
					{
						final = 0;
					}
					else if (final > 255)
					{
						final = 255;
					}
					tempimage[i + 1][j + 1] = final;
				}
			}

			for (int i = 0; i < 256; i++)
			{
				for (int k = 0; k < 256; k++)
				{
					image[i][k] = tempimage[i][k];
				}
			}

			savePGM("cat256_out.pgm", image);
			break;
		case 5:
			// Enter the code for vertical edge detection here

			for (int i = 0; i < 256; i++)
			{
				for (int k = 0; k < 256; k++)
				{
					tempimage[i][k] = image[i][k];
				}
			}
			for (int i = 0; i < 254; i++)
			{
				for (int j = 0; j < 254; j++)
				{
					int ch1, ch2, ch3, final;
					ch1 = image[i][j] * -1 + image[i][j + 2] * 1;
					ch2 = image[i + 1][j] * -2 + image[i + 1][j + 2] * 2;
					ch3 = image[i + 2][j] * -1 + image[i + 2][j + 2] * 1;
					final = (ch1 + ch3 + ch2);
					if (final < 0)
					{
						final = 0;
					}
					else if (final > 255)
					{
						final = 255;
					}
					tempimage[i + 1][j + 1] = final;
				}
			}
			for (int i = 0; i < 256; i++)
			{
				for (int k = 0; k < 256; k++)
				{
					image[i][k] = tempimage[i][k];
				}
			}

			savePGM("cat256_out.pgm", image);
			break;
		case 6:
			cout << "Exiting the program." << endl;
			break;

		case 7:

			//FOR BONUS MARKS!!
			//INVERTING THE ORIENTATION OF THE IMAGE.
			for (int i = 0, j = 0; i < 256; i++, j++)
			{
				for (int k = 0, l = 255; k < 256; k++, l--)
				{
					tempimage[i][k] = image[j][l];
				}
			}
			for (int i = 0; i < 256; i++)
			{
				for (int k = 0; k < 256; k++)
				{
					image[i][k] = tempimage[i][k];
				}
			}
			savePGM("cat256_out.pgm", image);

			break;

		case 8:
			//FOR BONUS MARKS!!
			//Complete edge detection of the image both horizontal and vertical.

			for (int i = 0; i < 256; i++)
			{
				for (int k = 0; k < 256; k++)
				{
					tempimage[i][k] = image[i][k];
				}
			}
			for (int i = 0; i < 256; i++)
			{
				for (int k = 0; k < 256; k++)
				{
					tempimage2[i][k] = image[i][k];
				}
			}

			for (int i = 0; i < 254; i++)
			{
				for (int j = 0; j < 254; j++)
				{
					int ch1, ch2, ch3, final;
					ch1 = image[i][j] * -1 + image[i][j + 2] * 1;
					ch2 = image[i + 1][j] * -2 + image[i + 1][j + 2] * 2;
					ch3 = image[i + 2][j] * -1 + image[i + 2][j + 2] * 1;
					final = (ch1 + ch3 + ch2);
					if (final < 0)
					{
						final = 0;
					}
					else if (final > 255)
					{
						final = 255;
					}
					tempimage2[i + 1][j + 1] = final;
				}
			}
			for (int i = 0; i < 254; i++)
			{
				for (int j = 0; j < 254; j++)
				{
					int ch1, ch2, final;
					ch1 = image[i][j] * -1 + image[i][j + 1] * -2 + image[i][j + 2] * -1;
					ch2 = image[i + 2][j] * 1 + image[i + 2][j + 1] * 2 + image[i + 2][j + 2] * 1;
					final = (ch1 + ch2);
					if (final < 0)
					{
						final = 0;
					}
					else if (final > 255)
					{
						final = 255;
					}
					tempimage[i + 1][j + 1] = final;
				}
			}
			for (int i = 0; i < 256; i++)
			{
				for (int k = 0; k < 256; k++)
				{
					image[i][k] = (tempimage[i][k] + tempimage2[i][k]) * 1 / 2;
				}
			}
			savePGM("cat256_out.pgm", image);
			break;

		case 9:

			//FOR BONUS MARKS!!
			//Sharpening the image.

			for (int i = 0; i < 256; i++)
			{
				for (int k = 0; k < 256; k++)
				{
					tempimage[i][k] = image[i][k];
				}
			}
			for (int i = 0; i < 254; i++)
			{
				for (int j = 0; j < 254; j++)
				{
					int ch1, ch2, ch3, final;
					ch1 = image[i][j] * 0 + image[i][j + 1] * -0.5 + image[i][j + 2] * 0;
					ch2 = image[i + 1][j] * -0.5 + image[i + 1][j + 1] * 3 + image[i + 1][j + 2] * -0.5;
					ch3 = image[i + 2][j] * 0 + image[i + 2][j + 1] * -0.5 + image[i + 2][j + 2] * 0;
					final = (ch1 + ch3 + ch2);
					if (final < 0)
					{
						final = 0;
					}
					else if (final > 255)
					{
						final = 255;
					}
					tempimage[i + 1][j + 1] = final;
				}
			}
			for (int i = 0; i < 256; i++)
			{
				for (int k = 0; k < 256; k++)
				{
					image[i][k] = tempimage[i][k];
				}
			}


			savePGM("cat256_out.pgm", image);
			break;

		default:
			cout << "Invalid choice. Please enter a valid option." << endl;
		}
	} while (choice != 6);

	return 0;
}