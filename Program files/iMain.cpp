#include<bits/stdc++.h>
#include<iGraphics.h>
using namespace std;

vector<string>card_set={"R0","R1","R1","R2","R2","R3","R3","R4","R4","R5","R5","R6","R6","R7","R7","R8","R8","R9","R9","B0","B1","B1","B2","B2","B3","B3","B4","B4","B5","B5","B6","B6","B7","B7","B8","B8","B9","B9","G0","G1","G1","G2","G2","G3","G3","G4","G4","G5","G5","G6","G6","G7","G7","G8","G8","G9","G9","Y0","Y1","Y1","Y2","Y2","Y3","Y3","Y4","Y4","Y5","Y5","Y6","Y6","Y7","Y7","Y8","Y8","Y9","Y9","RS","RS","RR","RR","R+2","R+2","+4","WC","BS","BS","BR","BR","B+2","B+2","+4","WC","GS","GS","GR","GR","G+2","G+2","+4","WC","YS","YS","YR","YR","Y+2","Y+2","+4","WC"};
map<string,int>card_image_index={{"R0",0},{"R1",1},{"R2",2},{"R3",3},{"R4",4},{"R5",5},{"R6",6},{"R7",7},{"R8",8},{"R9",9},{"R+2",10},{"RS",11},{"RR",12},{"B0",13},{"B1",14},{"B2",15},{"B3",16},{"B4",17},{"B5",18},{"B6",19},{"B7",20},{"B8",21},{"B9",22},{"B+2",23},{"BS",24},{"BR",25},{"G0",26},{"G1",27},{"G2",28},{"G3",29},{"G4",30},{"G5",31},{"G6",32},{"G7",33},{"G8",34},{"G9",35},{"G+2",36},{"GS",37},{"GR",38},{"Y0",39},{"Y1",40},{"Y2",41},{"Y3",42},{"Y4",43},{"Y5",44},{"Y6",45},{"Y7",46},{"Y8",47},{"Y9",48},{"Y+2",49},{"YS",50},{"YR",51},{"+4",52},{"WC",53},};
char card_image_address[54][25]={"Image\\UNO Cards\\R0.bmp","Image\\UNO Cards\\R1.bmp","Image\\UNO Cards\\R2.bmp","Image\\UNO Cards\\R3.bmp","Image\\UNO Cards\\R4.bmp","Image\\UNO Cards\\R5.bmp","Image\\UNO Cards\\R6.bmp","Image\\UNO Cards\\R7.bmp","Image\\UNO Cards\\R8.bmp","Image\\UNO Cards\\R9.bmp","Image\\UNO Cards\\R+2.bmp","Image\\UNO Cards\\RS.bmp","Image\\UNO Cards\\RR.bmp","Image\\UNO Cards\\B0.bmp","Image\\UNO Cards\\B1.bmp","Image\\UNO Cards\\B2.bmp","Image\\UNO Cards\\B3.bmp","Image\\UNO Cards\\B4.bmp","Image\\UNO Cards\\B5.bmp","Image\\UNO Cards\\B6.bmp","Image\\UNO Cards\\B7.bmp","Image\\UNO Cards\\B8.bmp","Image\\UNO Cards\\B9.bmp","Image\\UNO Cards\\B+2.bmp","Image\\UNO Cards\\BS.bmp","Image\\UNO Cards\\BR.bmp","Image\\UNO Cards\\G0.bmp","Image\\UNO Cards\\G1.bmp","Image\\UNO Cards\\G2.bmp","Image\\UNO Cards\\G3.bmp","Image\\UNO Cards\\G4.bmp","Image\\UNO Cards\\G5.bmp","Image\\UNO Cards\\G6.bmp","Image\\UNO Cards\\G7.bmp","Image\\UNO Cards\\G8.bmp","Image\\UNO Cards\\G9.bmp","Image\\UNO Cards\\G+2.bmp","Image\\UNO Cards\\GS.bmp","Image\\UNO Cards\\GR.bmp","Image\\UNO Cards\\Y0.bmp","Image\\UNO Cards\\Y1.bmp","Image\\UNO Cards\\Y2.bmp","Image\\UNO Cards\\Y3.bmp","Image\\UNO Cards\\Y4.bmp","Image\\UNO Cards\\Y5.bmp","Image\\UNO Cards\\Y6.bmp","Image\\UNO Cards\\Y7.bmp","Image\\UNO Cards\\Y8.bmp","Image\\UNO Cards\\Y9.bmp","Image\\UNO Cards\\Y+2.bmp","Image\\UNO Cards\\YS.bmp","Image\\UNO Cards\\YR.bmp","Image\\UNO Cards\\+4.bmp","Image\\UNO Cards\\WC.bmp"};
vector<string>cards;
vector<vector<string>>player_card={{},{},{},{}};
deque<int>turn,standings,playable_card_x,playable_card_index;
int player_number,skip,bgi_index=0,loading_index=1,loading_bar_image_index=0,reset_state=1,t,m,h,playable_card_count,draw_card_count,game_over,rev,turn_image_index,w,R,B,G,Y,i,j,r,n,c,p,x,y,d,UNO[4],penalty,loading_bgi,UNO_Voice[4],red,blue,green,yellow,rev1,skip1,draw2,draw4,rev_voice,skip_voice,draw2_voice,draw4_voice,red_voice,blue_voice,green_voice,yellow_voice,draw_voice,card_dealing_sound,standings_bgm,menu_bgm_index,match_played_2,match_played_3,match_played_4,pos1_2,pos2_2,pos1_3,pos2_3,pos3_3,pos1_4,pos2_4,pos3_4,pos4_4;
string current_card,s,color;
char str[5];
char loading_bar_image_address[4][25]={"Image\\Loading_Bar_1.bmp","Image\\Loading_Bar_2.bmp","Image\\Loading_Bar_3.bmp","Image\\Loading_Bar_4.bmp"};
char bgi_address[14][35]={"Image\\Starting.bmp","Image\\Menu.bmp","Image\\Player_Number.bmp","Image\\Loading_2.bmp","Image\\Play.bmp","Image\\Pause_Menu.bmp","Image\\Restart_Confirmation.bmp","Image\\Quit_Confirmation.bmp","Image\\Standings.bmp","Image\\Statistics.bmp","Image\\Instructions.bmp","Image\\How_To_Play_1.bmp","Image\\How_To_Play_2.bmp","Image\\About.bmp"};
char serial_image_address[4][15]={"Image\\1.bmp","Image\\2.bmp","Image\\3.bmp","Image\\4.bmp"};
char player_image_address[4][20]={"Image\\You_2.bmp","Image\\Player1_2.bmp","Image\\Player2_2.bmp","Image\\Player3_2.bmp"};
char turn_image_red_address[2][40]={"Image\\Turn_Clockwise_Red.bmp","Image\\Turn_Anticlockwise_Red.bmp"};
char turn_image_blue_address[2][40]={"Image\\Turn_Clockwise_Blue.bmp","Image\\Turn_Anticlockwise_Blue.bmp"};
char turn_image_green_address[2][40]={"Image\\Turn_Clockwise_Green.bmp","Image\\Turn_Anticlockwise_Green.bmp"};
char turn_image_yellow_address[2][40]={"Image\\Turn_Clockwise_Yellow.bmp","Image\\Turn_Anticlockwise_Yellow.bmp"};

int number_of_digit(int n)
{
	int d=0;
	if(n==0)
	{
		return 1;
	}
	while(n!=0)
	{
		n=n/10;
		d++;
	}
	return d;
}

void reset()
{
	cards=card_set;
	for(i=0;i<4;i++)
	{
		player_card[i].clear();
	}
	turn.clear();
	standings.clear();
	t=-1,j=0,m=0,w=0,game_over=0,draw_card_count=0,skip=-1,rev=0,UNO[0]=0,UNO[1]=0,UNO[2]=0,UNO[3]=0,turn_image_index=0,penalty=0,loading_bgi=0,UNO_Voice[0]=0,UNO_Voice[1]=0,UNO_Voice[2]=0,UNO_Voice[3]=0,red=0,blue=0,green=0,yellow=0,rev1=0,skip1=0,draw2=0,draw4=0,rev_voice=0,skip_voice=0,draw2_voice=0,draw4_voice=0,red_voice=0,blue_voice=0,green_voice=0,yellow_voice=0,draw_voice=0,card_dealing_sound=0,standings_bgm=0;
	for(i=0;i<player_number;i++)
	{
		for(j=0;j<7;j++)
		{
			r=rand()%cards.size();
			player_card[i].push_back(cards[r]);
			cards.erase(cards.begin()+r);
		}
	}
	for(i=0;i<player_number;i++)
	{
		turn.push_back(i);
	}
	r=rand()%50;
	current_card=cards[r];
	cards.erase(cards.begin()+r);
	color=current_card[0];
}

void draw_card(int p)
{
    r=rand()%cards.size();
    player_card[p].push_back(cards[r]);
    cards.erase(cards.begin()+r);                                                                                                                     
}

void card_operation()
{
    n=(t+1)%h;
    if(current_card=="+4")
    {
        for(i=0;i<4;i++)
        {
            draw_card(turn[n]);
        }
		draw4=1;
    }
    else if(current_card[1]=='+')
    {
        for(i=0;i<2;i++)
        {
            draw_card(turn[n]);
        }
		draw2=1;
    }
    else if(current_card[1]=='R')
    {
		rev=0;
		rev1=1;
        if(turn.size()>2)
        {
            p=m-1;
        	if(p<0)
            {
            	p=p+h;
            }
            n=turn[p];
            reverse(turn.begin(),turn.end());
            for(i=0;;i++)
            {
                turn.push_front(turn[turn.size()-1]);
                turn.pop_back();
                if(turn[m+1]==n)
                {
                    break;
                }
            }
        }
    	else
		{
			reverse(turn.begin(),turn.end());
    	}
    }
	if(current_card[1]=='S')
	{
		skip1=1;
	}
    if(current_card[1]=='S' || current_card[1]=='+')
    {
        t++;
    }
	if(current_card[1]=='S' || current_card[1]=='+' || current_card=="+4")
	{
		skip=turn[n];
	}
	if(current_card!="+4" && current_card!="WC")
	{
		color=current_card[0];
	}
}

void play()
{
	playable_card_count=0;
	c=turn[m];
	for(i=0;i<player_card[turn[m]].size();i++)
	{
		s=player_card[turn[m]][i];
		if(s=="+4" || s=="WC" || current_card[0]==s[0] || current_card[1]==s[1])
		{
			playable_card_count++;
		}
	}
	if(playable_card_count==0)
	{
		if(draw_card_count==0)
		{
			draw_card(turn[m]);
			draw_card_count++;
		}
		else
		{
			draw_card_count=0;
			t++;
		}
	}
	else
	{
		for(i=0;i<player_card[turn[m]].size();i++)
		{
			s=player_card[turn[m]][i];
			if(s=="+4" || s=="WC" || current_card[0]==s[0] || current_card[1]==s[1])
			{
				current_card=s;
				auto x=find(player_card[turn[m]].begin(),player_card[turn[m]].end(),current_card);
				player_card[turn[m]].erase(x);
				cards.push_back(current_card);
				if(player_card[turn[m]].size()==0)
				{
					standings.push_back(turn[m]);
					turn.erase(turn.begin()+m);
					h--;
					t=(((t-m)*h)/(h+1))+m-1;
					if(current_card[1]=='R')
					{
						t++;
					}
				}
				if(h>1)
				{
					card_operation();
				}
				else
				{
					standings.push_back(turn[0]);
				}
				break;
			}
		}
		R=0,B=0,G=0,Y=0;
		if((current_card=="+4" || current_card=="WC") && player_card[c].size()!=0)
		{
			for(i=0;i<player_card[c].size();i++)
			{
				if(player_card[c][i][0]=='R')
				{
					R++;
				}
				else if(player_card[c][i][0]=='B')
				{
					B++;
				}
				else if(player_card[c][i][0]=='G')
				{
					G++;
				}
				else if(player_card[c][i][0]=='Y')
				{
					Y++;
				}
			}
			c=max({R,B,G,Y});
			if(c==R)
			{
				color="R";
				red=1;
			}
			else if(c==B)
			{
				color="B";
				blue=1;
			}
			else if(c==G)
			{
				color="G";
				green=1;
			}
			else if(c==Y)
			{
				color="Y";
				yellow=1;
			}
		}
		if(current_card=="+4")
		{
			current_card=color+"C+";
			t++;
		}
		else if(current_card=="WC")
		{
			current_card=color+"C-";
		}
		t++;
		draw_card_count=0;
	}
	if(player_card[0].size()>1 || player_card[0].size()==0)
	{
		UNO[0]=0;
		UNO_Voice[0]=0;
	}
	for(i=1;i<4;i++)
	{
		if(player_card[i].size()==1)
		{
			UNO[i]=1;
		}
		else
		{
			UNO[i]=0;
			UNO_Voice[i]=0;
		}
	}
}

void iDraw() 
{
	iClear();
	if(bgi_index==0)
	{
		iShowBMP(0,0,bgi_address[0]);
		if(loading_index==1)
		{
			iShowBMP(600,225,"Image\\Loading_1.bmp");
		}
		iShowBMP(500,140,loading_bar_image_address[loading_bar_image_index]);
	}
	else if(bgi_index==1)
	{
		iShowBMP(0,0,bgi_address[1]);
	}
	else if(bgi_index==2)
	{
		iShowBMP(0,0,bgi_address[2]);
		iShowBMP(1400,0,"Image\\Back_Button.bmp");
	}
	else if(bgi_index==3)
	{
		iShowBMP(0,0,bgi_address[3]);
		loading_bgi++;
		j=0;
	}
	else if(bgi_index==4)
	{
		iShowBMP(0,0,bgi_address[4]);
		iShowBMP(1450,700,"Image\\Pause_Button.bmp");
		if(t==-1)
		{
			if(card_dealing_sound==0)
			{
				PlaySound(TEXT("Music\\Card_Dealing_Sound.wav"),NULL,SND_ASYNC | SND_LOOP);
				card_dealing_sound=1;
			}
			if(j<=7*player_number)
			{
				for(i=0;i<30;i=i+3)
				{
					iShowBMP(549+i,310+i/3,"Image\\UNO Cards\\UNO_Card_Back_1.bmp");
				}
			}
			else
			{
				Sleep(600);
				for(i=0;i<30;i=i+3)
				{
					iShowBMP(1260+i,430+i/3,"Image\\UNO Cards\\UNO_Card_Back_1.bmp");
				}
				iShowBMP(562.5,310,card_image_address[card_image_index[current_card]]);
			}
			iShowBMP(570,10,"Image\\You_1.bmp");
			if(player_number==2)
			{
				iShowBMP(570,710,"Image\\Player1_1H.bmp");
				for(i=0;i<j && i<7*player_number;i++)
				{	
					if(i%player_number==0)
					{
						iShowBMP(484.5+i*26/player_number,50,"Image\\UNO Cards\\UNO_Card_Back_4.bmp");
					}
					else if(i%player_number==1)
					{
						iShowBMP(484.5+(i-1)*26/player_number,535,"Image\\UNO Cards\\UNO_Card_Back_1.bmp");
					}
				}
			}
			else if(player_number==3)
			{
				iShowBMP(1140,347.5,"Image\\Player1_1V.bmp");
				iShowBMP(60,347.5,"Image\\Player2_1V.bmp");
				for(i=0;i<j && i<7*player_number;i++)
				{
					if(i%player_number==0)
					{
						iShowBMP(484.5+i*26/player_number,50,"Image\\UNO Cards\\UNO_Card_Back_4.bmp");
					}
					else if(i%player_number==1)
					{
						iShowBMP(965,262+(i-1)*26/player_number,"Image\\UNO Cards\\UNO_Card_Back_2.bmp");
					}
					else if(i%player_number==2)
					{
						iShowBMP(100,262+(i-2)*26/player_number,"Image\\UNO Cards\\UNO_Card_Back_3.bmp");
					}
				}
			}
			else if(player_number==4)
			{
				iShowBMP(1140,347.5,"Image\\Player1_1V.bmp");
				iShowBMP(570,710,"Image\\Player2_1H.bmp");
				iShowBMP(60,347.5,"Image\\Player3_1.bmp");
				for(i=0;i<j && i<7*player_number;i++)
				{	
					if(i%player_number==0)
					{
						iShowBMP(484.5+i*26/player_number,50,"Image\\UNO Cards\\UNO_Card_Back_4.bmp");
					}
					else if(i%player_number==1)
					{
						iShowBMP(965,262+(i-1)*26/player_number,"Image\\UNO Cards\\UNO_Card_Back_2.bmp");
					}
					else if(i%player_number==2)
					{
						iShowBMP(484.5+(i-2)*26/player_number,535,"Image\\UNO Cards\\UNO_Card_Back_1.bmp");
					}
					else if(i%player_number==3)
					{
						iShowBMP(100,262+(i-3)*26/player_number,"Image\\UNO Cards\\UNO_Card_Back_3.bmp");
					}
				}
			}
			if(j>7*player_number)
			{
				for(i=0;i<7;i++)
				{
					iShowBMP(397.5+i*55,50,card_image_address[card_image_index[player_card[0][i]]]);
				}
			}
			if(j==7*player_number)
			{
				PlaySound(0,0,0);
			}
			j++;
			if(j==7*player_number+3)
			{
				iShowBMP(495,352.5,"Image\\Start.bmp");
			}
			if(j==7*player_number+4)
			{
				t=0;
				PlaySound(TEXT("Music\\Game_Start.wav"),NULL,SND_SYNC);
				PlaySound(TEXT("Music\\Game_BGM.wav"),NULL,SND_ASYNC | SND_LOOP);
			}
			Sleep(50);
		}
		else
		{
			for(i=0;i<30;i=i+3)
			{
				iShowBMP(1260+i,430+i/3,"Image\\UNO Cards\\UNO_Card_Back_1.bmp");
			}
			if(UNO[0]==0)
			{
				iShowBMP(1250,250,"Image\\UNO_Button_1.bmp");
			}
			else if(UNO[0]==1)
			{
				iShowBMP(1250,250,"Image\\UNO_Button_2.bmp");
			}
			if(current_card=="+4" || current_card[2]=='+')
			{
				iShowBMP(562.5,310,card_image_address[card_image_index["+4"]]);
				if(turn[m]==0 && w==1)
				{
					iShowBMP(750,313,"Image\\Color_Selection.bmp");
				}
			}
			else if(current_card=="WC" || current_card[2]=='-')
			{
				iShowBMP(562.5,310,card_image_address[card_image_index["WC"]]);
				if(turn[m]==0 && w==1)
				{
					iShowBMP(750,313,"Image\\Color_Selection.bmp");
				}
			}
			else
			{
				iShowBMP(562.5,310,card_image_address[card_image_index[current_card]]);
			}
			if((current_card[2]=='+' || current_card[2]=='-') && player_card[0].size()!=0)
			{
				if(current_card[0]=='R')
				{
					iShowBMP(750,313,"Image\\Red.bmp");
				}
				else if(current_card[0]=='B')
				{
					iShowBMP(750,313,"Image\\Blue.bmp");
				}
				else if(current_card[0]=='G')
				{
					iShowBMP(750,313,"Image\\Green.bmp");
				}
				else if(current_card[0]=='Y')
				{
					iShowBMP(750,313,"Image\\Yellow.bmp");
				}
			}
			if(current_card[1]=='R')
			{
				if(rev==0 && player_card[0].size()!=0)
				{
					if(h>2)
					{
						if(current_card[0]=='R')
						{
							iShowBMP(562.5,310,turn_image_red_address[turn_image_index]);
						}
						else if(current_card[0]=='B')
						{
							iShowBMP(562.5,310,turn_image_blue_address[turn_image_index]);
						}
						else if(current_card[0]=='G')
						{
							iShowBMP(562.5,310,turn_image_green_address[turn_image_index]);
						}
						else if(current_card[0]=='Y')
						{
							iShowBMP(562.5,310,turn_image_yellow_address[turn_image_index]);
						}
					}
					if(turn_image_index==0)
					{
						turn_image_index=1;
					}
					else
					{
						turn_image_index=0;
					}
					rev++;
				}
			}
			if(player_card[0].size()!=0)
			{
				if(rev1==1)
				{
					rev_voice++;
					if(rev_voice==2)
					{
						PlaySound(0,0,0);
						Sleep(50);
						PlaySound(TEXT("Music\\Reverse.wav"),NULL,SND_SYNC);
						rev1=0;
						rev_voice=0;
						PlaySound(TEXT("Music\\Game_BGM.wav"),NULL,SND_ASYNC | SND_LOOP);
					}
				}
				if(skip1==1)
				{
					skip_voice++;
					if(skip_voice==2)
					{
						PlaySound(0,0,0);
						Sleep(50);
						PlaySound(TEXT("Music\\Skip.wav"),NULL,SND_SYNC);
						skip1=0;
						skip_voice=0;
						PlaySound(TEXT("Music\\Game_BGM.wav"),NULL,SND_ASYNC | SND_LOOP);
					}
				}
				if(draw2==1)
				{
					draw2_voice++;
					if(draw2_voice==2)
					{
						PlaySound(TEXT("Music\\Draw2.wav"),NULL,SND_SYNC);
						draw2=0;
						draw2_voice=0;
						PlaySound(TEXT("Music\\Game_BGM.wav"),NULL,SND_ASYNC | SND_LOOP);
					}
				}
				if(draw4==1)
				{
					draw4_voice++;
					if(draw4_voice==2)
					{
						PlaySound(TEXT("Music\\Draw4.wav"),NULL,SND_SYNC);
						draw4=0;
						draw4_voice=0;
					}
					if(red==1)
					{
						red_voice++;
						if(red_voice==2)
						{
							PlaySound(TEXT("Music\\Red.wav"),NULL,SND_SYNC);
							red=0;
							red_voice=0;
							PlaySound(TEXT("Music\\Game_BGM.wav"),NULL,SND_ASYNC | SND_LOOP);
						}
					}
					else if(blue==1)
					{
						blue_voice++;
						if(blue_voice==2)
						{
							PlaySound(TEXT("Music\\Blue.wav"),NULL,SND_SYNC);
							blue=0;
							blue_voice=0;
							PlaySound(TEXT("Music\\Game_BGM.wav"),NULL,SND_ASYNC | SND_LOOP);
						}
					}
					else if(green==1)
					{
						green_voice++;
						if(green_voice==2)
						{
							PlaySound(TEXT("Music\\Green.wav"),NULL,SND_SYNC);
							green=0;
							green_voice=0;
							PlaySound(TEXT("Music\\Game_BGM.wav"),NULL,SND_ASYNC | SND_LOOP);
						}
					}
					else if(yellow==1)
					{
						yellow_voice++;
						if(yellow_voice==2)
						{
							PlaySound(TEXT("Music\\Yellow.wav"),NULL,SND_SYNC);
							yellow=0;
							yellow_voice=0;
							PlaySound(TEXT("Music\\Game_BGM.wav"),NULL,SND_ASYNC | SND_LOOP);
						}
					}
				}
				else
				{
					if(red==1)
					{
						red_voice++;
						if(red_voice==2)
						{
							PlaySound(TEXT("Music\\Red.wav"),NULL,SND_SYNC);
							red=0;
							red_voice=0;
							PlaySound(TEXT("Music\\Game_BGM.wav"),NULL,SND_ASYNC | SND_LOOP);
						}
					}
					else if(blue==1)
					{
						blue_voice++;
						if(blue_voice==2)
						{
							PlaySound(TEXT("Music\\Blue.wav"),NULL,SND_SYNC);
							blue=0;
							blue_voice=0;
							PlaySound(TEXT("Music\\Game_BGM.wav"),NULL,SND_ASYNC | SND_LOOP);
						}
					}
					else if(green==1)
					{
						green_voice++;
						if(green_voice==2)
						{
							PlaySound(TEXT("Music\\Green.wav"),NULL,SND_SYNC);
							green=0;
							green_voice=0;
							PlaySound(TEXT("Music\\Game_BGM.wav"),NULL,SND_ASYNC | SND_LOOP);
						}
					}
					else if(yellow==1)
					{
						yellow_voice++;
						if(yellow_voice==2)
						{
							PlaySound(TEXT("Music\\Yellow.wav"),NULL,SND_SYNC);
							yellow=0;
							yellow_voice=0;
							PlaySound(TEXT("Music\\Game_BGM.wav"),NULL,SND_ASYNC | SND_LOOP);
						}
					}
				}
			}
			m=t%h;
			x=615-((55*player_card[0].size())+50)/2;
			for(i=0;i<player_card[0].size();i++)
			{
				s=player_card[0][i];
				if(turn[m]==0 && w==0 && (s=="+4" || s=="WC" || current_card[0]==s[0] || current_card[1]==s[1]))
				{
					y=80;
				}
				else
				{
					y=50;
				}
				iShowBMP(x,y,card_image_address[card_image_index[player_card[0][i]]]);
				x+=55;
				iShowBMP(570,10,"Image\\You_1.bmp");
			}
			if(skip==0)
			{
				iShowBMP2(575,92.5,"Image\\Skip.bmp",255);
				skip=-1;
			}
			if(player_card[0].size()==1 && UNO[0]==1)
			{
				iShowBMP(677.5,112.5,"Image\\UNO_Mark_1.bmp");
				if(UNO_Voice[0]==1)
				{
					PlaySound(TEXT("Music\\UNO.wav"),NULL,SND_SYNC);
					PlaySound(TEXT("Music\\Game_BGM.wav"),NULL,SND_ASYNC | SND_LOOP);
				}
				UNO_Voice[0]++;
			}
			else if(player_card[0].size()==1 && UNO[0]==0)
			{
				draw_card(0);
				draw_card(0);
				iShowBMP(555,112.5,"Image\\Penalty.bmp");
				PlaySound(TEXT("Music\\Penalty_Sound.wav"),NULL,SND_ASYNC);
				PlaySound(TEXT("Music\\Game_BGM.wav"),NULL,SND_ASYNC | SND_LOOP);
				penalty=1;
			}
			if(player_number==2)
			{
				if(player_card[1].size()>7)
				{
					d=160/(player_card[1].size()-1);
				}
				else
				{
					d=26;
				}
				x=615-(d*(player_card[1].size()-1)+105)/2;
				for(j=0;j<player_card[1].size();j++)
				{
					iShowBMP(x,535,"Image\\UNO Cards\\UNO_Card_Back_1.bmp");
					x+=d;
					iShowBMP(570,710,"Image\\Player1_1H.bmp");
				}
				if(skip==1 && player_card[0].size()!=0)
				{
					iShowBMP2(575,577.5,"Image\\Skip.bmp",255);
					skip=-1;
				}
				if(UNO[1]==1 && player_card[0].size()!=0)
				{
					iShowBMP(472.5,597.5,"Image\\UNO_Mark_1.bmp");
					if(UNO_Voice[1]==1)
					{
						PlaySound(TEXT("Music\\UNO.wav"),NULL,SND_SYNC);
						PlaySound(TEXT("Music\\Game_BGM.wav"),NULL,SND_ASYNC | SND_LOOP);
					}
					UNO_Voice[1]++;
				}
			}
			else if(player_number==3)
			{
				for(i=1;i<player_number;i++)
				{
					if(i==1)
					{
						if(player_card[1].size()>7)
						{
							d=160/(player_card[1].size()-1);
						}
						else
						{
							d=26;
						}
						y=392.5-(d*(player_card[1].size()-1)+105)/2;
						for(j=0;j<player_card[1].size();j++)
						{
							iShowBMP(965,y,"Image\\UNO Cards\\UNO_Card_Back_2.bmp");
							y+=d;
							iShowBMP(1140,347.5,"Image\\Player1_1V.bmp");
						}
						if(skip==1 && player_card[0].size()!=0)
						{
							iShowBMP2(1007.5,352.5,"Image\\Skip.bmp",255);
							skip=-1;
						}
						if(UNO[1]==1 && player_card[0].size()!=0)
						{
							iShowBMP(1027.5,455,"Image\\UNO_Mark_2.bmp");
							if(UNO_Voice[1]==1)
							{
								PlaySound(TEXT("Music\\UNO.wav"),NULL,SND_SYNC);
								PlaySound(TEXT("Music\\Game_BGM.wav"),NULL,SND_ASYNC | SND_LOOP);
							}
							UNO_Voice[1]++;
						}
					}
					else
					{
						if(player_card[2].size()>7)
						{
							d=160/(player_card[2].size()-1);
						}
						else
						{
							d=26;
						}
						y=392.5-(d*(player_card[2].size()-1)+105)/2;
						for(j=0;j<player_card[2].size();j++)
						{
							iShowBMP(100,y,"Image\\UNO Cards\\UNO_Card_Back_3.bmp");
							y+=d;
							iShowBMP(60,347.5,"Image\\Player2_1V.bmp");
						}
						if(skip==2 && player_card[0].size()!=0)
						{
							iShowBMP2(142.5,352.5,"Image\\Skip.bmp",255);
							skip=-1;
						}
						if(UNO[2]==1 && player_card[0].size()!=0)
						{
							iShowBMP2(162.5,250,"Image\\UNO_Mark_3.bmp",255);
							if(UNO_Voice[2]==1)
							{
								PlaySound(TEXT("Music\\UNO.wav"),NULL,SND_SYNC);
								PlaySound(TEXT("Music\\Game_BGM.wav"),NULL,SND_ASYNC | SND_LOOP);
							}
							UNO_Voice[2]++;
						}
					}
				}
			}
			else
			{
				for(i=1;i<player_number;i++)
				{
					if(i==1)
					{
						if(player_card[1].size()>7)
						{
							d=160/(player_card[1].size()-1);
						}
						else
						{
							d=26;
						}
						y=392.5-(d*(player_card[1].size()-1)+105)/2;
						for(j=0;j<player_card[1].size();j++)
						{
							iShowBMP(965,y,"Image\\UNO Cards\\UNO_Card_Back_2.bmp");
							y+=d;
							iShowBMP(1140,347.5,"Image\\Player1_1V.bmp");
						}
						if(skip==1 && player_card[0].size()!=0)
						{
							iShowBMP2(1007.5,352.5,"Image\\Skip.bmp",255);
							skip=-1;
						}
						if(UNO[1]==1 && player_card[0].size()!=0)
						{
							iShowBMP(1027.5,455,"Image\\UNO_Mark_2.bmp");
							if(UNO_Voice[1]==1)
							{
								PlaySound(TEXT("Music\\UNO.wav"),NULL,SND_SYNC);
								PlaySound(TEXT("Music\\Game_BGM.wav"),NULL,SND_ASYNC | SND_LOOP);
							}
							UNO_Voice[1]++;
						}
					}
					else if(i==2)
					{
						if(player_card[2].size()>7)
						{
							d=160/(player_card[2].size()-1);
						}
						else
						{
							d=26;
						}
						x=615-(d*(player_card[2].size()-1)+105)/2;
						for(j=0;j<player_card[2].size();j++)
						{
							iShowBMP(x,535,"Image\\UNO Cards\\UNO_Card_Back_1.bmp");
							x+=d;
							iShowBMP(570,710,"Image\\Player2_1H.bmp");
						}
						if(skip==2 && player_card[0].size()!=0)
						{
							iShowBMP2(575,577.5,"Image\\Skip.bmp",255);
							skip=-1;
						}
						if(UNO[2]==1 && player_card[0].size()!=0)
						{
							iShowBMP(472.5,597.5,"Image\\UNO_Mark_1.bmp");
							if(UNO_Voice[2]==1)
							{
								PlaySound(TEXT("Music\\UNO.wav"),NULL,SND_SYNC);
								PlaySound(TEXT("Music\\Game_BGM.wav"),NULL,SND_ASYNC | SND_LOOP);
							}
							UNO_Voice[2]++;
						}
					}
					else
					{
						if(player_card[3].size()>7)
						{
							d=160/(player_card[3].size()-1);
						}
						else
						{
							d=26;
						}
						y=392.5-(d*(player_card[3].size()-1)+105)/2;
						for(j=0;j<player_card[3].size();j++)
						{
							iShowBMP(100,y,"Image\\UNO Cards\\UNO_Card_Back_3.bmp");
							y+=d;
							iShowBMP(60,347.5,"Image\\Player3_1.bmp");
						}
						if(skip==3 && player_card[0].size()!=0)
						{
							iShowBMP2(142.5,352.5,"Image\\Skip.bmp",255);
							skip=-1;
						}
						if(UNO[3]==1 && player_card[0].size()!=0)
						{
							iShowBMP(162.5,250,"Image\\UNO_Mark_3.bmp");
							if(UNO_Voice[3]==1)
							{
								PlaySound(TEXT("Music\\UNO.wav"),NULL,SND_SYNC);
								PlaySound(TEXT("Music\\Game_BGM.wav"),NULL,SND_ASYNC | SND_LOOP);
							}
							UNO_Voice[3]++;
						}
					}
				}
			}
			if(player_number==2)
			{
				switch(turn[m])
				{
					case 0:
						iShowBMP2(595,270,"Image\\Arrow_1.bmp",0);
						break;
					case 1:
						iShowBMP2(595,485,"Image\\Arrow_2.bmp",0);
						break;
				}
			}
			else if(player_number==3)
			{
				switch(turn[m])
				{
					case 0:
						iShowBMP2(595,270,"Image\\Arrow_1.bmp",0);
						break;
					case 1:
						iShowBMP2(682.5,372.5,"Image\\Arrow_4.bmp",0);
						break;
					case 2:
						iShowBMP2(517.5,372.5,"Image\\Arrow_3.bmp",0);
						break;
				}
			}
			else
			{
				switch(turn[m])
				{
					case 0:
						iShowBMP2(595,270,"Image\\Arrow_1.bmp",0);
						break;
					case 1:
						iShowBMP2(682.5,372.5,"Image\\Arrow_4.bmp",0);
						break;
					case 2:
						iShowBMP2(595,485,"Image\\Arrow_2.bmp",0);
						break;
					case 3:
						iShowBMP2(517.5,372.5,"Image\\Arrow_3.bmp",0);
						break;
				}
			}
			if(player_card[0].size()!=0)
			{
				Sleep(1000);
			}
			if(turn[m]!=0 && h>1)
			{
				play();
			}
			if(h==1)
			{
				game_over++;
				PlaySound(0,0,0);
			}
			if(game_over==3)
			{
				Sleep(2000);
				bgi_index=8;
			}
		}
	}
	else if(bgi_index==5)
	{
		iShowBMP(0,0,bgi_address[5]);
	}
	else if(bgi_index==6)
	{
		iShowBMP(0,0,bgi_address[6]);
	}
	else if(bgi_index==7)
	{
		iShowBMP(0,0,bgi_address[7]);
	}
	else if(bgi_index==8)
	{
		iShowBMP(0,0,bgi_address[8]);
		if(standings_bgm==0)
		{
			PlaySound(TEXT("Music\\Standings_BGM.wav"),NULL,SND_ASYNC);
			ifstream fin;
			fin.open("Statistics.txt");
			fin>>match_played_2>>match_played_3>>match_played_4>>pos1_2>>pos1_3>>pos1_4>>pos2_2>>pos2_3>>pos2_4>>pos3_3>>pos3_4>>pos4_4;
			fin.close();
			if(player_number==2)
			{
				match_played_2++;
				if(standings[0]==0)
				{
					pos1_2++;
				}
				else if(standings[1]==0)
				{
					pos2_2++;
				}
			}
			else if(player_number==3)
			{
				match_played_3++;
				if(standings[0]==0)
				{
					pos1_3++;
				}
				else if(standings[1]==0)
				{
					pos2_3++;
				}
				else if(standings[2]==0)
				{
					pos3_3++;
				}
			}
			else if(player_number==4)
			{
				match_played_4++;
				if(standings[0]==0)
				{
					pos1_4++;
				}
				else if(standings[1]==0)
				{
					pos2_4++;
				}
				else if(standings[2]==0)
				{
					pos3_4++;
				}
				else if(standings[3]==0)
				{
					pos4_4++;
				}
			}
			ofstream fout;
			fout.open("Statistics.txt");
			fout<<match_played_2<<' '<<match_played_3<<' '<<match_played_4<<' '<<pos1_2<<' '<<pos1_3<<' '<<pos1_4<<' '<<pos2_2<<' '<<pos2_3<<' '<<pos2_4<<' '<<pos3_3<<' '<<pos3_4<<' '<<pos4_4;
			fout.close();
			standings_bgm++;
		}
		iShowBMP(1400,0,"Image\\Back_Button.bmp");
		y=500;
		for(i=0;i<player_number;i++)
		{
			iShowBMP2(610,y,serial_image_address[i],0);
			if(standings[i]==0)
			{
				iShowBMP2(650,y,player_image_address[0],0);
			}
			else if(standings[i]==1)
			{
				iShowBMP2(650,y,player_image_address[1],0);
			}
			else if(standings[i]==2)
			{
				iShowBMP2(650,y,player_image_address[2],0);
			}
			else if(standings[i]==3)
			{
				iShowBMP2(650,y,player_image_address[3],0);
			}
			y-=45;
		}
	}
	else if(bgi_index==9)
	{
		iShowBMP(0,0,bgi_address[9]);
		iShowBMP(1400,0,"Image\\Back_Button.bmp");
		ifstream fin;
		fin.open("Statistics.txt");
		fin>>match_played_2>>match_played_3>>match_played_4>>pos1_2>>pos1_3>>pos1_4>>pos2_2>>pos2_3>>pos2_4>>pos3_3>>pos3_4>>pos4_4;
		fin.close();
		iSetColor(0,0,0);
		sprintf(str,"%d",match_played_2);
		iText(705-6*number_of_digit(match_played_2),455,str,GLUT_BITMAP_TIMES_ROMAN_24);
		sprintf(str,"%d",match_played_3);
		iText(875-6*number_of_digit(match_played_3),455,str,GLUT_BITMAP_TIMES_ROMAN_24);
		sprintf(str,"%d",match_played_4);
		iText(1045-6*number_of_digit(match_played_4),455,str,GLUT_BITMAP_TIMES_ROMAN_24);
		sprintf(str,"%d",pos1_2);
		iText(705-6*number_of_digit(pos1_2),410,str,GLUT_BITMAP_TIMES_ROMAN_24);
		sprintf(str,"%d",pos1_3);
		iText(875-6*number_of_digit(pos1_3),410,str,GLUT_BITMAP_TIMES_ROMAN_24);
		sprintf(str,"%d",pos1_4);
		iText(1045-6*number_of_digit(pos1_4),410,str,GLUT_BITMAP_TIMES_ROMAN_24);
		sprintf(str,"%d",pos2_2);
		iText(705-6*number_of_digit(pos2_2),365,str,GLUT_BITMAP_TIMES_ROMAN_24);
		sprintf(str,"%d",pos2_3);
		iText(875-6*number_of_digit(pos2_3),365,str,GLUT_BITMAP_TIMES_ROMAN_24);
		sprintf(str,"%d",pos2_4);
		iText(1045-6*number_of_digit(pos2_4),365,str,GLUT_BITMAP_TIMES_ROMAN_24);
		sprintf(str,"%d",pos3_3);
		iText(875-6*number_of_digit(pos3_3),320,str,GLUT_BITMAP_TIMES_ROMAN_24);
		sprintf(str,"%d",pos3_4);
		iText(1045-6*number_of_digit(pos3_4),320,str,GLUT_BITMAP_TIMES_ROMAN_24);
		sprintf(str,"%d",pos4_4);
		iText(1045-6*number_of_digit(pos4_4),275,str,GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(bgi_index==10)
	{
		iShowBMP(0,0,bgi_address[10]);
		iShowBMP(1400,0,"Image\\Next_Button.bmp");
	}
	else if(bgi_index==11)
	{
		iShowBMP(0,0,bgi_address[11]);
		iShowBMP(1400,0,"Image\\Next_Button.bmp");
	}
	else if(bgi_index==12)
	{
		iShowBMP(0,0,bgi_address[12]);
		iShowBMP(1400,0,"Image\\Back_Button.bmp");
	}
	else if(bgi_index==13)
	{
		iShowBMP(0,0,bgi_address[13]);
		iShowBMP(1400,0,"Image\\Back_Button.bmp");
	}
	if(loading_bgi==2)
	{
		Sleep(3000);
		PlaySound(0,0,0);
		bgi_index=4;
		loading_bgi=0;
	}
}

void iMouse(int button,int state,int mx,int my) 
{
	if(bgi_index==1 && menu_bgm_index==1)
	{
		if(state==GLUT_UP && mx>=600 && mx<=900 && my>=400 && my<=450)
		{
			PlaySound(TEXT("Music\\Click_Sound_1.wav"),NULL,SND_ASYNC);
			bgi_index=2;
		}
		else if(state==GLUT_UP && mx>=600 && mx<=900 && my>=300 && my<=350)
		{
			PlaySound(TEXT("Music\\Click_Sound_1.wav"),NULL,SND_ASYNC);
			bgi_index=9;
		}
		else if(state==GLUT_UP && mx>=600 && mx<=900 && my>=200 && my<=250)
		{
			PlaySound(TEXT("Music\\Click_Sound_1.wav"),NULL,SND_ASYNC);
			bgi_index=10;
		}
		else if(state==GLUT_UP && mx>=600 && mx<=900 && my>=100 && my<=150)
		{
			PlaySound(TEXT("Music\\Click_Sound_1.wav"),NULL,SND_ASYNC);
			bgi_index=13;
		}
	}
	else if(bgi_index==2)
	{
		if(state==GLUT_UP && mx>=1400 && mx<=1500 && my>=0 && my<=40)
		{
			PlaySound(TEXT("Music\\Click_Sound_1.wav"),NULL,SND_ASYNC);
			bgi_index=1;
		}
		else if(state==GLUT_UP && mx>=500 && mx<=600 && my>=350 && my<=450)
		{
			PlaySound(TEXT("Music\\Click_Sound_1.wav"),NULL,SND_SYNC);
			player_number=2;
			h=2;
			bgi_index=3;
		}
		else if(state==GLUT_UP && mx>=700 && mx<=800 && my>=350 && my<=450)
		{
			PlaySound(TEXT("Music\\Click_Sound_1.wav"),NULL,SND_SYNC);
			player_number=3;
			h=3;
			bgi_index=3;
		}
		else if(state==GLUT_UP && mx>=900 && mx<=1000 && my>=350 && my<=450)
		{
			PlaySound(TEXT("Music\\Click_Sound_1.wav"),NULL,SND_SYNC);
			player_number=4;
			h=4;
			bgi_index=3;
		}
		reset();
	}
	else if(bgi_index==4 && t>-1)
	{
		if(state==GLUT_UP && mx>=1450 && mx<=1490 && my>=700 && my<=740)
		{
			PlaySound(TEXT("Music\\Click_Sound_1.wav"),NULL,SND_SYNC);
			bgi_index=5;
		}
		else if(turn[m]==0 && player_card[0].size()==2 && state==GLUT_UP && mx>=1285 && mx<=1365 && my>=280 && my<=360)
		{
			UNO[0]=1;
		}
		else if(turn[m]==0 && w==1 && h>1 && state==GLUT_UP && mx>=750 && mx<=830 && my>=310 && my<=390)
		{
			if(mx>=750 && mx<=790 && my>=350 && my<=390)
			{
				color="R";
				red=1;
			}
			else if(mx>=790 && mx<=830 && my>=350 && my<=390)
			{
				color="B";
				blue=1;
			}
			else if(mx>=750 && mx<=790 && my>=310 && my<=350)
			{
				color="G";
				green=1;
			}
			else if(mx>=790 && mx<=830 && my>=310 && my<=350)
			{
				color="Y";
				yellow=1;
			}
			if(current_card=="+4")
			{
				current_card=color+"C+";
				t++;
			}
			else if(current_card=="WC")
			{
				current_card=color+"C-";
			}
			t++;
			w=0;
		}
		else if(turn[m]==0 && w==0 && h>1 && state==GLUT_UP)
		{
			playable_card_count=0;
			x=615-(55*(player_card[0].size()-1)+105)/2;
			for(i=0;i<player_card[0].size();i++)
			{
				s=player_card[0][i];
				if(s=="+4" || s=="WC" || current_card[0]==s[0] || current_card[1]==s[1])
				{
					playable_card_count++;
					playable_card_index.push_back(i);
					playable_card_x.push_back(x);
				}
				x+=55;
			}
			if(playable_card_count==0)
			{
				if(mx>=1260 && mx<=1392 && my>=428 && my<=604)
				{
					draw_card(0);
					playable_card_count=0;
					for(i=0;i<player_card[0].size();i++)
					{
						s=player_card[0][i];
						if(s=="+4" || s=="WC" || current_card[0]==s[0] || current_card[1]==s[1])
						{
							playable_card_count++;
						}
					}
					if(playable_card_count==0)
					{
						t++;
					}
				}
			}
			else
			{
				for(i=0;i<playable_card_x.size()-1;i++)
				{
					if(mx>=playable_card_x[i] && mx<=playable_card_x[i]+55 && my>=90 && my<=255)
					{
						current_card=player_card[0][playable_card_index[i]];
						auto x=find(player_card[turn[m]].begin(),player_card[turn[m]].end(),current_card);
						player_card[turn[m]].erase(x);
						cards.push_back(current_card);
						if(player_card[turn[m]].size()==0)
						{
							standings.push_back(turn[m]);
							turn.erase(turn.begin()+m);
							h--;
							t=(((t-m)*h)/(h+1))+m-1;
							if(current_card[1]=='R')
							{
								t++;
							}
						}
						if(h>1)
						{
							card_operation();
						}
						else
						{
							standings.push_back(turn[0]);
						}
						if(current_card!="+4" && current_card!="WC")
						{
							t++;
						}
						else
						{
							w=1;
						}
						break;
					}
				}
				if(mx>=playable_card_x[playable_card_x.size()-1] && mx<=playable_card_x[i]+105 && my>=80 && my<=245)
				{
					current_card=player_card[0][playable_card_index[playable_card_x.size()-1]];
					auto x=find(player_card[turn[m]].begin(),player_card[turn[m]].end(),current_card);
					player_card[turn[m]].erase(x);
					cards.push_back(current_card);
					if(player_card[turn[m]].size()==0)
					{
						standings.push_back(turn[m]);
						turn.erase(turn.begin()+m);
						h--;
						t=(((t-m)*h)/(h+1))+m-1;
						if(current_card[1]=='R')
						{
							t++;
						}
					}
					if(h>1)
					{
						card_operation();
					}
					else
					{
						standings.push_back(turn[0]);
					}
					if(current_card!="+4" && current_card!="WC")
					{
						t++;
					}
					else
					{
						w=1;
					}
				}
				playable_card_index.clear();
				playable_card_x.clear();
				draw_card_count=0;
			}
			if(player_card[0].size()>1 || player_card[0].size()==0)
			{
				UNO[0]=0;
				UNO_Voice[0]=0;
			}
			for(i=1;i<4;i++)
			{
				if(player_card[i].size()==1)
				{
					UNO[i]=1;
				}
				else
				{
					UNO[i]=0;
					UNO_Voice[i]=0;
				}
			}
		}
	}
	else if(bgi_index==5)
	{
		if(state==GLUT_UP && mx>=600 && mx<=900 && my>=500 && my<=550)
		{
			PlaySound(TEXT("Music\\Click_Sound_1.wav"),NULL,SND_ASYNC);
			PlaySound(TEXT("Music\\Game_BGM.wav"),NULL,SND_ASYNC | SND_LOOP);
			bgi_index=4;
		}
		else if(state==GLUT_UP && mx>=600 && mx<=900 && my>=400 && my<=450)
		{
			PlaySound(TEXT("Music\\Click_Sound_2.wav"),NULL,SND_ASYNC);
			bgi_index=6;
		}
		else if(state==GLUT_UP && mx>=600 && mx<=900 && my>=300 && my<=350)
		{
			PlaySound(TEXT("Music\\Click_Sound_2.wav"),NULL,SND_ASYNC);
			bgi_index=7;
		}
	}
	else if(bgi_index==6)
	{
		if(state==GLUT_UP && mx>=590 && mx<=710 && my>=350 && my<=400)
		{
			PlaySound(TEXT("Music\\Click_Sound_1.wav"),NULL,SND_ASYNC);
			h=player_number;
			reset();
			Sleep(1000);
			bgi_index=3;
		}
		else if(state==GLUT_UP && mx>=790 && mx<=910 && my>=350 && my<=400)
		{
			PlaySound(TEXT("Music\\Click_Sound_1.wav"),NULL,SND_ASYNC);
			bgi_index=5;
		}
	}
	else if(bgi_index==7)
	{
		if(state==GLUT_UP && mx>=590 && mx<=710 && my>=350 && my<=400)
		{
			PlaySound(TEXT("Music\\Click_Sound_1.wav"),NULL,SND_ASYNC);
			Sleep(1000);
			bgi_index=1;
		}
		else if(state==GLUT_UP && mx>=790 && mx<=910 && my>=350 && my<=400)
		{
			PlaySound(TEXT("Music\\Click_Sound_1.wav"),NULL,SND_ASYNC);
			bgi_index=5;
		}
	}
	else if(bgi_index==9)
	{
		if(state==GLUT_UP && mx>=1400 && mx<=1500 && my>=0 && my<=40)
		{
			PlaySound(TEXT("Music\\Click_Sound_1.wav"),NULL,SND_ASYNC);
			bgi_index=1;
		}
	}
	else if(bgi_index==10)
	{
		if(state==GLUT_UP && mx>=1400 && mx<=1500 && my>=0 && my<=40)
		{
			PlaySound(TEXT("Music\\Click_Sound_1.wav"),NULL,SND_ASYNC);
			bgi_index=11;
		}
	}
	else if(bgi_index==11)
	{
		if(state==GLUT_UP && mx>=1400 && mx<=1500 && my>=0 && my<=40)
		{
			PlaySound(TEXT("Music\\Click_Sound_1.wav"),NULL,SND_ASYNC);
			bgi_index=12;
		}
	}
	else if(bgi_index!=0 && bgi_index!=3)
	{
		if(state==GLUT_UP && mx>=1400 && mx<=1500 && my>=0 && my<=40)
		{
			PlaySound(TEXT("Music\\Click_Sound_1.wav"),NULL,SND_ASYNC);
			bgi_index=1;
		}
	}
}

void iMouseMove(int mx,int my){}
void iKeyboard(unsigned char k){}
void iSpecialKeyboard(unsigned char k){}

void change_loading_index()
{
	loading_index*=-1;
}

void change_loading_bar_image_index()
{
	loading_bar_image_index++;
}

void change_bgi_index()
{
	if(bgi_index==0)
	{
		bgi_index=1;
	}
}

void play_menu_bgm()
{
	PlaySound(TEXT("Music\\Menu_BGM.wav"),NULL,SND_SYNC);
	iPauseTimer(3);
}

void change_menu_bgm_index()
{
	menu_bgm_index=1;
}

int main()
{
	srand(time(0));
	iSetTimer(300,change_loading_index);
	iSetTimer(6000,change_loading_bar_image_index);
	iSetTimer(24000,change_bgi_index);
	iSetTimer(24400,play_menu_bgm);
	iSetTimer(33000,change_menu_bgm_index);
	PlaySound(TEXT("Music\\Intro_BGM.wav"),NULL,SND_ASYNC);
	iInitialize(1500,750,"UNO KINGDOM");
	return 0;
}