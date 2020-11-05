

#define  colorRed {230, 25, 75}
#define  colorGreen {60, 180, 75}
#define  colorYellow {255, 225, 25}
#define  colorBlue {0, 130, 200}
#define  colorOrange {245, 130, 48}
#define  colorPurple {145, 30, 180}
#define  colorCyan {70, 240, 240}
#define  colorMagenta {240, 50, 230}
#define  colorLime {210, 245, 60}
#define  colorPink {250, 190, 212}
#define  colorTeal {0, 128, 128}
#define  colorLavender {220, 190, 255}
//#define color'(170, 110, 40)'
//#define color'(255, 250, 200)',
//#define color'(128, 0, 0)'
//#define color'(170, 255, 195)'
//#define color'(128, 128, 0)'
//#define color'(255, 215, 180)'
#define  colorNavy {0, 0, 128}
#define  colorGrey {128, 128, 128}
#define  colorWhite {255, 255,255}
#define  colorBlack {0, 0, 0}


uint8_t playerColors[11][10][3]{ 
	{colorWhite,colorWhite,colorWhite,colorWhite,colorWhite,colorWhite,colorWhite,colorWhite,colorWhite,colorWhite}, //index 0
	{colorWhite,colorWhite,colorWhite,colorWhite,colorWhite,colorWhite,colorWhite,colorWhite,colorWhite,colorWhite}, //1
	{colorWhite,colorWhite,colorWhite,colorRed,colorWhite,colorGreen,colorWhite,colorWhite,colorWhite,colorWhite}, //2
	{colorWhite,colorWhite,colorWhite,colorRed,colorGreen,colorYellow,colorWhite,colorWhite,colorWhite,colorWhite}, //3
	{colorWhite,colorWhite,colorRed,colorGreen,colorWhite,colorYellow,colorBlue,colorWhite,colorWhite,colorWhite}, //4 
	{colorWhite,colorWhite,colorRed,colorGreen,colorYellow,colorBlue,colorOrange,colorWhite,colorWhite,colorWhite}, //5 
	{colorRed,colorRed,colorGreen,colorYellow,colorWhite,colorBlue,colorOrange,colorPurple,colorPurple,colorWhite}, //6 
	{colorRed,colorRed,colorGreen,colorYellow,colorBlue,colorOrange,colorPurple,colorCyan,colorCyan,colorWhite},  //7
	{colorRed,colorRed,colorGreen,colorYellow,colorBlue,colorOrange,colorPurple,colorCyan,colorCyan,colorNavy}, //8 5 & 8 op de kop
	{colorRed,colorGreen,colorYellow,colorBlue,colorWhite,colorOrange,colorPurple,colorCyan,colorNavy,colorWhite}, //9 8 naast mekaar
	{colorRed,colorGreen,colorYellow,colorBlue,colorMagenta,colorOrange,colorPurple,colorCyan,colorNavy,colorLime}, //10
};