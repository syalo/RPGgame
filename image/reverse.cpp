void s_reverse(int x,int y,int board[12][12],int mask[12][12]){
	
	if(board[y][x] != 1){//�����ς݂Ȃ�X���[
		board[y][x] = 1;

		if(mask[y-1][x-1] == 0){
			s_reverse(x-1,y-1,board,mask);
		}else{
			board[y-1][x-1] = 1;
		}
		
		if(mask[y-1][x] == 0){
			s_reverse(x,y-1,board,mask);
		}else{
			board[y-1][x] = 1;
		}
		
		if(mask[y-1][x+1] == 0){
			s_reverse(x+1,y-1,board,mask);
		}else{
			board[y-1][x+1] = 1;
		}
		
		if(mask[y][x-1] == 0){
			s_reverse(x-1,y,board,mask);
		}else{
			board[y][x-1] = 1;
		}
		
		if(mask[y][x+1] == 0){
			s_reverse(x+1,y,board,mask);
		}else{
			board[y][x+1] = 1;
		}
		
		if(mask[y+1][x-1] == 0){
			s_reverse(x-1,y+1,board,mask);
		}else{
			board[y+1][x-1] = 1;
		}
		
		if(mask[y+1][x] == 0){
			s_reverse(x,y+1,board,mask);
		}else{
			board[y+1][x] = 1;
		}
		
		if(mask[y+1][x+1] == 0){
			s_reverse(x+1,y+1,board,mask);
		}else{
			if(board[y+1][x+1] != -1)board[y+1][x+1] = 1;
		}
	}

}


void L_button_reverse(int x,int y,int board[12][12],int mask[12][12]){
	
	if(mask[y/40][x/40-1] != 0){
		board[y/40][x/40-1] = 1;//�����ς݃}�[�N������
	}else{
		s_reverse(x/40-1,y/40,board,mask);
	}

}

void R_button_reverse(int x,int y,int board[12][12]){
	
	if(board[y/40][x/40-1] == 0){
		board[y/40][x/40-1] = -3;//�N���b�N�s�}�[�N������
	}else if(board[y/40][x/40-1] == -3){
		board[y/40][x/40-1] = 0;//�N���b�N�s�}�[�N���O��
	}
}