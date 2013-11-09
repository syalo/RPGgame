bool clear_check(int board[12][12],int mask[12][12],int mine_sum){
	
	int count = 0;
	
	for(int i = 1;i < 11;i++){
		for(int j = 1;j < 11;j++){
			if(mask[i][j] != -2 && board[i][j] == 1)count++;
		}
	}
	if(count == (100 - mine_sum)){
		return true;
	}else{
		return false;
	}
}