//
// Created by zcx on 2023/10/19.
//

#include "Chess.h"
using namespace std;

// 判断在指定坐标(x,y)位置，是否是有效点击
// 如果是有效点击，把有效点击的位置(行，列）保存在参数pos中
bool Chess::clickBoard(int x, int y, ChessPos* pos){

	if (x-margin.x <= -grade_size.x * 0.4f || x >= end.x + grade_size.x * 0.4f)
		return False;
	if (y-margin.y <= -grade_size.y * 0.4f || y >= end.y + grade_size.y * 0.4f)
		return False;

	int left_top_col = floor((x - margin.x) / grade_size.x);
	int left_top_row = floor((y - margin.y) / grade_size.y);

	float left_x = margin.x + left_top_col * grade_size.x;
	float top_y = margin.y + left_top_row * grade_size.y;

	// 圆形算法
	float YUXZHI = pow(grade_size.x * 0.4f, 2) + pow(grade_size.y * 0.4f, 2);
	multimap<float, unsigned int> map4;
	for (unsigned int i = 0; i < 4; i++) {
		unsigned int dx = i & 0x01;
		unsigned int dy = (i & 0x02) >> 1;
		float res = pow(x - dx * grade_size.x - left_x, 2) + pow(y - dy * grade_size.y - top_y, 2);
		map4.insert(make_pair(res, i));
	}
	if (map4.begin()->first < YUXZHI) {
		unsigned int add_x = (map4.begin()->second) & 0x01;
		pos->col = left_top_col + add_x;
		unsigned int add_y = ((map4.begin()->second) & 0x02) >> 1;
		pos->row = left_top_row + add_y;
		return True;
	}
	return False;

	//// 矩形算法
	//xypos YUXZHI = { grade_size.x * 0.4f, grade_size.y * 0.4f };
	//float dx = x - left_x;
	//float dy = y - top_y;

	//if ((dx < YUXZHI.x || (grade_size.x - dx) < YUXZHI.x) && (dy < YUXZHI.y || (grade_size.y - dy) < YUXZHI.y)){
	//	pos->col = (dx < grade_size.x * 0.5) ? left_top_col : (left_top_col + 1);
	//	pos->row = (dy < grade_size.y * 0.5) ? left_top_row : (left_top_row + 1);
	//	return True;
	//}
	//return False;//// 矩形算法

}



// 在棋盘的指定位置（pos）, 落子（kind）
void Chess::chessDown(ChessPos* pos, chess_kind_t kind){
	int x = margin.x + pos->col * grade_size.x - 0.5f * chess_size;
	int y = margin.y + pos->row * grade_size.y - 0.5f * chess_size;
	if (kind == CHESS_BLACK) {
		putimagePNG(x, y, &chessBlackImg);
	}
	else if (kind == CHESS_WHITE) {
		putimagePNG(x, y, &chessWhiteImg);
	}
}

void Chess::set_chessMap(ChessPos* pos, chess_kind_t kind) {
	chessMap[pos->col][pos->row] = kind;
}


// 获取棋盘的大小（13线、15线、19线）
int Chess::get_grade_num(){
	return grade_num;
}

// 获取指定位置是黑棋，还是白棋，还是空白
int Chess::getChessData(ChessPos* pos){

	return chessMap[pos->col][pos->row];
}
int Chess::getChessData(int row, int col){

	return chessMap[col][row];
}

// 判断棋局是否结束
bool Chess::checkOver(){

	return 0;
}

static void putimagePNG(int x, int y, IMAGE* picture) //x为载入图片的X坐标，y为Y坐标
{
	// 变量初始化
	DWORD* dst = GetImageBuffer();    // GetImageBuffer()函数，用于获取绘图设备的显存指针，EASYX自带
	DWORD* draw = GetImageBuffer();
	DWORD* src = GetImageBuffer(picture); //获取picture的显存指针
	int picture_width = picture->getwidth(); //获取picture的宽度，EASYX自带
	int picture_height = picture->getheight(); //获取picture的高度，EASYX自带
	int graphWidth = getwidth();       //获取绘图区的宽度，EASYX自带
	int graphHeight = getheight();     //获取绘图区的高度，EASYX自带
	int dstX = 0;    //在显存里像素的角标

	// 实现透明贴图 公式： Cp=αp*FP+(1-αp)*BP ， 贝叶斯定理来进行点颜色的概率计算
	for (int iy = 0; iy < picture_height; iy++)
	{
		for (int ix = 0; ix < picture_width; ix++)
		{
			int srcX = ix + iy * picture_width; //在显存里像素的角标
			int sa = ((src[srcX] & 0xff000000) >> 24); //0xAArrggbb;AA是透明度
			int sr = ((src[srcX] & 0xff0000) >> 16); //获取RGB里的R
			int sg = ((src[srcX] & 0xff00) >> 8);   //G
			int sb = src[srcX] & 0xff;              //B
			if (ix >= 0 && ix <= graphWidth && iy >= 0 && iy <= graphHeight && dstX <= graphWidth * graphHeight)
			{
				dstX = (ix + x) + (iy + y) * graphWidth; //在显存里像素的角标
				int dr = ((dst[dstX] & 0xff0000) >> 16);
				int dg = ((dst[dstX] & 0xff00) >> 8);
				int db = dst[dstX] & 0xff;
				draw[dstX] = ((sr * sa / 255 + dr * (255 - sa) / 255) << 16)  //公式： Cp=αp*FP+(1-αp)*BP  ； αp=sa/255 , FP=sr , BP=dr
					| ((sg * sa / 255 + dg * (255 - sa) / 255) << 8)         //αp=sa/255 , FP=sg , BP=dg
					| (sb * sa / 255 + db * (255 - sa) / 255);              //αp=sa/255 , FP=sb , BP=db
			}
		}
	}
}
