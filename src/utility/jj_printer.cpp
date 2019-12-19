#include "utility/jj_printer.h"

using namespace std;
void print_joshtrick()
{
	const char* HORZ = u8"─";   // HORiZontal line
	const char* VERT = u8"│";   // VERTical line
	const char* TL = u8"┌";     // Top Left
	const char* TR = u8"┐";     // Top Right
	const char* BL = u8"└";     // Bottom Left
	const char* BR = u8"┘";     // Bottom Right
  string top = TL;
  string bottom = BL;
	for (int n = 0; n < 64; n++) {
		top += HORZ;
		bottom += HORZ;
	}
  top += TR;
  bottom += BR;
  cout << top << endl;
  cout << VERT << "........####...########.....##########.####....####............." << VERT << endl;
  cout << VERT << "........####.####....####.####.........####....####............." << VERT << endl;
  cout << VERT << "........####.####....####.....######...####....####............." << VERT << endl;
  cout << VERT << "........####.####....####.........####.############............." << VERT << endl;
  cout << VERT << "####....####.####....####.........####.####....####............." << VERT << endl;
  cout << VERT << "..########.....########...##########...####....####............." << VERT << endl;
  cout << VERT << "                                                                " << VERT << endl;
  cout << VERT << "############.##########...############...########...####......##" << VERT << endl;
  cout << VERT << "....####.....####....####.....####.....####....####.####....####" << VERT << endl;
  cout << VERT << "....####.....####....####.....####.....####.........############" << VERT << endl;
  cout << VERT << "....####.....##########.......####.....####.........##########.." << VERT << endl;
  cout << VERT << "....####.....####....##.......####.....####....####.####....####" << VERT << endl;
  cout << VERT << "....####.....####....####.############...########...####......##" << VERT << endl;
  cout << bottom << endl;
}
