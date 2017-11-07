#include<iostream>
#include<string>
//#include<stdlib.h>
using namespace std;
int main(){
	cout<<"Welcome to the 4 variable k-map simplifier\n";
	int m[16];
	for(int i=0;i<16;i++) m[i]=0;	//initializing all the minterms with 0 initially
	
	int n,p=0;
	cout<<"\nEnter the number of minterms you wanna enter:";
	cin>>n;
	cout<<"Enter the minterms:";
	for(int i=0;i<n;i++){
		cin>>p;
		m[p]=1;
	}
	/*cout<<"minterms are:";
	for(int i=0;i<16;i++){
		if(m[i]==1) cout<<i<<" ";
	}*/
	//cout<<"m[16]="<<m[16];
	//making pairs
	bool m_pairs[32];	//bcoz a total of 32 pairs is possible
	//making all the possible pairs and covering them using if-conditions
	//	1.horizontal pairs
	if(m[0]==1 && m[1]==1) m_pairs[0]=1;
	if(m[1]==1 && m[3]==1) m_pairs[1]=1;
	if(m[3]==1 && m[2]==1) m_pairs[2]=1;
	if(m[4]==1 && m[5]==1) m_pairs[3]=1;
	if(m[5]==1 && m[7]==1) m_pairs[4]=1;
	if(m[7]==1 && m[6]==1) m_pairs[5]=1;
	if(m[12]==1 && m[13]==1) m_pairs[6]=1;
	if(m[13]==1 && m[15]==1) m_pairs[7]=1;
	if(m[15]==1 && m[14]==1) m_pairs[8]=1;
	if(m[8]==1 && m[9]==1) m_pairs[9]=1;
	if(m[9]==1 && m[11]==1) m_pairs[10]=1;
	if(m[11]==1 && m[10]==1) m_pairs[11]=1;
	//	2.verical pairs
	if(m[0]==1 && m[4]==1) m_pairs[12]=1;
	if(m[1]==1 && m[5]==1) m_pairs[13]=1;
	if(m[3]==1 && m[7]==1) m_pairs[14]=1;
	if(m[2]==1 && m[6]==1) m_pairs[15]=1;
	if(m[4]==1 && m[12]==1) m_pairs[16]=1;
	if(m[5]==1 && m[13]==1) m_pairs[17]=1;
	if(m[7]==1 && m[15]==1) m_pairs[18]=1;
	if(m[6]==1 && m[14]==1) m_pairs[19]=1;
	if(m[12]==1 && m[8]==1) m_pairs[20]=1;
	if(m[13]==1 && m[9]==1) m_pairs[21]=1;
	if(m[15]==1 && m[11]==1) m_pairs[22]=1;
	if(m[14]==1 && m[10]==1) m_pairs[23]=1;
	//	3.corners or map folding
	if(m[0]==1 && m[8]==1) m_pairs[24]=1;
	if(m[1]==1 && m[9]==1) m_pairs[25]=1;
	if(m[3]==1 && m[11]==1) m_pairs[26]=1;
	if(m[2]==1 && m[10]==1) m_pairs[27]=1;
	if(m[0]==1 && m[2]==1) m_pairs[28]=1;
	if(m[4]==1 && m[6]==1) m_pairs[29]=1;
	if(m[12]==1 && m[14]==1) m_pairs[30]=1;
	if(m[8]==1 && m[10]==1) m_pairs[31]=1;
	
	/*cout<<"minterm pairs:\n";
	for(int i=0;i<32;i++){
		cout<<i<<"."<<m_pairs[i]<<endl;
	}*/
	
	/*i can make a quad using 2 approaches:
		1. combining all possible 4 1s
		2. combining 2 pairs..
			Since, i'll already get pairs I can combine the nearest pairs to get the quads and then i wouldn't have code for all the possible 4 ones to check for all possible quads
	*/		
	
	bool m_quad[24];	//bcoz 24 quads are possible
	//covering all possible quads using if conditions
	//	1.squares
	if((m_pairs[0]==1) && (m_pairs[3]==1)) m_quad[0]=1;
	if((m_pairs[1]==1) && (m_pairs[4]==1)) m_quad[1]=1;
	if((m_pairs[2]==1) && (m_pairs[5]==1)) m_quad[2]=1;
	if((m_pairs[3]==1) && (m_pairs[6]==1)) m_quad[3]=1;
	if((m_pairs[4]==1) && (m_pairs[7]==1)) m_quad[4]=1;
	if((m_pairs[5]==1) && (m_pairs[8]==1)) m_quad[5]=1;
	if((m_pairs[6]==1) && (m_pairs[9]==1)) m_quad[6]=1;
	if((m_pairs[7]==1) && (m_pairs[10]==1)) m_quad[7]=1;
	if((m_pairs[8]==1) && (m_pairs[11]==1)) m_quad[8]=1;
	//	2.edges
	if((m_pairs[0]==1) && (m_pairs[9]==1)) m_quad[9]=1;
	if((m_pairs[1]==1) && (m_pairs[10]==1)) m_quad[10]=1;
	if((m_pairs[2]==1) && (m_pairs[11]==1)) m_quad[11]=1;
	if((m_pairs[12]==1) && (m_pairs[15]==1)) m_quad[12]=1;
	if((m_pairs[16]==1) && (m_pairs[19]==1)) m_quad[13]=1;
	if((m_pairs[20]==1) && (m_pairs[23]==1)) m_quad[14]=1;
	//	3.horizontal
	if((m_pairs[0]==1) && (m_pairs[2]==1)) m_quad[15]=1;
	if((m_pairs[3]==1) && (m_pairs[5]==1)) m_quad[16]=1;
	if((m_pairs[6]==1) && (m_pairs[8]==1)) m_quad[17]=1;
	if((m_pairs[9]==1) && (m_pairs[11]==1)) m_quad[18]=1;
	//	4.vertical
	if((m_pairs[12]==1) && (m_pairs[20]==1)) m_quad[19]=1;
	if((m_pairs[13]==1) && (m_pairs[21]==1)) m_quad[20]=1;
	if((m_pairs[14]==1) && (m_pairs[22]==1)) m_quad[21]=1;
	if((m_pairs[15]==1) && (m_pairs[23]==1)) m_quad[22]=1;
	//	5.corner
	if((m_pairs[28]==1) && (m_pairs[31]==1)) m_quad[23]=1;
	
	/*just like quads, I can also make octets by combining the quads..*/
	bool m_octet[8];
	//covering all octets now..
	//	1.vertical
	if((m_quad[19]==1) && (m_quad[20]==1)) m_octet[0]=1;
	if((m_quad[20]==1) && (m_quad[21]==1)) m_octet[1]=1;
	if((m_quad[21]==1) && (m_quad[22]==1)) m_octet[2]=1;
	//	2.horizontal
	if((m_quad[15]==1) && (m_quad[16]==1)) m_octet[3]=1;
	if((m_quad[16]==1) && (m_quad[17]==1)) m_octet[4]=1;
	if((m_quad[17]==1) && (m_quad[18]==1)) m_octet[5]=1;
	//	3.corners
	if((m_quad[15]==1) && (m_quad[18]==1)) m_octet[6]=1;
	if((m_quad[19]==1) && (m_quad[22]==1)) m_octet[7]=1;
	
	//only one way is possible to cover the k-map with all ones..so:
	bool m_sixteen=0;	//it can be obtained by combining 2 octets
	if(m_octet[0]==1 && m_octet[2]==1) m_sixteen=1;
	
	string simplified;
	
	if(m_sixteen==1){		//if the input covered the whole k-map with ones
		cout<<"\nThe simplified function will be = 1"<<endl;
		exit(0);
	}
	for(int i=0;i<=16;i++){
		if(m[i]==1) break;
		else{
			if(i==16){			//if there are no ones in the whole k-map i.e no the k-map is empty
				cout<<"\nThe simplified finction will be = 0";
				exit(0);
			}
		}
	}
	
	//evaluating minimized expression now
	//	1.octets
	if(m_octet[0]==1) simplified=simplified+"a' + ";
	if(m_octet[1]==1) simplified=simplified+"b + ";
	if(m_octet[2]==1) simplified=simplified+"a + ";
	if(m_octet[3]==1) simplified=simplified+"c' + ";
	if(m_octet[4]==1) simplified=simplified+"d + ";
	if(m_octet[5]==1) simplified=simplified+"c + ";
	if(m_octet[6]==1) simplified=simplified+"d' + ";
	if(m_octet[7]==1) simplified=simplified+"b' + ";
	//	2.quads
	if(m_quad[0]==1){
		if(m_quad[2]==0 && m_quad[6]==0){
			simplified=simplified+"a'c' + ";
		}
	}
	if(m_quad[1]==1){
		if(m_quad[7]==0 && m_quad[12]==0){
			simplified=simplified+"bc' + ";
		}
	}
	if(m_quad[2]==1){
		if(m_quad[0]==0 && m_quad[8]==0){
			simplified=simplified+"ac' + ";
		}
	}
	if(m_quad[3]==1){
		if(m_quad[5]==0 && m_quad[9]==0){
			simplified=simplified+"a'd + ";
		}
	}
	if(m_quad[4]==1){
		if(m_quad[10]==0 && m_quad[13]==0){
			simplified=simplified+"bd + ";
		}
	}
	if(m_quad[5]==1){
		if(m_quad[3]==0 && m_quad[11]==0){
			simplified=simplified+"a'd + ";
		}
	}
	if(m_quad[6]==1){
		if(m_quad[0]==0 && m_quad[8]==0){
			simplified=simplified+"a'c' + ";
		}
	}
	if(m_quad[7]==1){
		if(m_quad[1]==0 && m_quad[14]==0){
			simplified=simplified+"bc + ";
		}
	}
	if(m_quad[8]==1){
		if(m_quad[2]==0 && m_quad[6]==0){
			simplified=simplified+"ac + ";
		}
	}
	if(m_quad[9]==1){
		if(m_quad[11]==0 && m_quad[3]==0){
			simplified=simplified+"a'd' + ";
		}
	}
	if(m_quad[10]==1){
		if(m_quad[4]==0 && m_quad[12]==0){
			simplified=simplified+"bd' + ";
		}
	}
	if(m_quad[11]==1){
		if(m_quad[9]==0 && m_quad[5]==0){
			simplified=simplified+"ad' + ";
		}
	}
	if(m_quad[12]==1){
		if(m_quad[14]==0 && m_quad[1]==0){
			simplified=simplified+"b'c + ";
		}
	}
	if(m_quad[13]==1){
		if((m_quad[4]==0 )&& (m_quad[14]==0 || m_quad[14]==0)){
			simplified=simplified+"b'd + ";
		}
	}
	if(m_quad[14]==1){
		if(m_quad[12]==0 && m_quad[7]==0){
			simplified=simplified+"b'd' + ";
		}
	}
	//	3.pairs
	if(m_pairs[0]==1){
		if(m_pairs[2]==0 && m_pairs[3]==0 && m_pairs[9]==0){
			simplified=simplified+"a'c'd' + ";
		}
	}
	if(m_pairs[1]==1){
		if((m_pairs[4]==0 && m_pairs[10]==0) && (m_pairs[0]==0 || m_pairs[1]==0)){
			simplified=simplified+"bc'd' + ";
		}
	}
	if(m_pairs[2]==1){
		if(m_pairs[0]==0 && m_pairs[5]==0 && m_pairs[11]==0){
			simplified=simplified+"ac'd' + ";
		}
	}
	if(m_pairs[3]==1){
		if(m_pairs[0]==0 && m_pairs[6]==0 && m_pairs[5]==0){
			simplified=simplified+"a'c'd + ";
		}
	}
	if(m_pairs[4]==1){
		if((m_pairs[1]==0 && m_pairs[7]==0) && (m_pairs[3]==0 || m_pairs[5]==0)){
			simplified=simplified+"b'c'd + ";
		}
	}
	if(m_pairs[5]==1){
		if(m_pairs[3]==0 && m_pairs[2]==0 && m_pairs[8]==0){
			simplified=simplified+"ac'd + ";
		}
	}
	if(m_pairs[6]==1){
		if(m_pairs[3]==0 && m_pairs[8]==0 && m_pairs[9]==0){
			simplified=simplified+"a'cd + ";
		}
	}
	if(m_pairs[7]==1){
		if((m_pairs[4]==0 && m_pairs[10]==0) && (m_pairs[6]==0 || m_pairs[8]==0)){
			simplified=simplified+"bcd + ";
		}
	}
	if(m_pairs[8]==1){
		if(m_pairs[6]==0 && m_pairs[5]==0 && m_pairs[11]==0){
			simplified=simplified+"acd + ";
		}
	}
	if(m_pairs[9]==1){
		if(m_pairs[11]==0 && m_pairs[11]==0 && m_pairs[0]==0){
			simplified=simplified+"a'cd' + ";
		}
	}
	if(m_pairs[10]==1){
		if((m_pairs[7]==0 && m_pairs[1]==0) && (m_pairs[9]==0 || m_pairs[11]==0)){
			simplified=simplified+"bcd' + ";
		}
	}
	if(m_pairs[11]==1){
		if(m_pairs[9]==0 && m_pairs[8]==0 && m_pairs[2]==0){
			simplified=simplified+"acd' + ";
		}
	}
	if(m_pairs[12]==1){
		if(m_pairs[13]==0 && m_pairs[15]==0 && m_pairs[20]==0){
			simplified=simplified+"a'b'c' + ";
		}
	}
	if(m_pairs[13]==1){
		if(m_pairs[12]==0 && m_pairs[14]==0 && m_pairs[17]==0){
			simplified=simplified+"a'bc' + ";
		}
	}
	if(m_pairs[14]==1){
		if(m_pairs[13]==0 && m_pairs[15]==0 && m_pairs[18]==0){
			simplified=simplified+"abc' + ";
		}
	}
	if(m_pairs[15]==1){
		if(m_pairs[14]==0 && m_pairs[12]==0 && m_pairs[19]==0){
			simplified=simplified+"ab'c' + ";
		}
	}
	if(m_pairs[16]==1){
		if((m_pairs[17]==0 && m_pairs[19]==0) && (m_pairs[12]==0 || m_pairs[20]==0)){
			simplified=simplified+"a'b'd + ";
		}
	}
	if(m_pairs[17]==1){
		if((m_pairs[16]==0 && m_pairs[18]==0) && (m_pairs[13]==0 || m_pairs[21]==0)){
			simplified=simplified+"a'bd + ";
		}
	}
	if(m_pairs[18]==1){
		if((m_pairs[17]==0 && m_pairs[19]==0) && (m_pairs[14]==0 || m_pairs[22]==0)){
			simplified=simplified+"abd + ";
		}
	}
	if(m_pairs[19]==1){
		if((m_pairs[18]==0 && m_pairs[16]==0) && (m_pairs[15]==0 || m_pairs[23]==0)){
			simplified=simplified+"ab'd + ";
		}
	}	
	if(m_pairs[20]==1){
		if(m_pairs[21]==0 && m_pairs[23]==0 && m_pairs[12]==0){
			simplified=simplified+"a'b'c + ";
		}
	}
	if(m_pairs[21]==1){
		if(m_pairs[20]==0 && m_pairs[22]==0 && m_pairs[13]==0){
			simplified=simplified+"a''bc + ";
		}
	}
	if(m_pairs[22]==1){
		if(m_pairs[21]==0 && m_pairs[23]==0 && m_pairs[14]==0){
			simplified=simplified+"abc + ";
		}
	}
	if(m_pairs[23]==1){
		if(m_pairs[22]==0 && m_pairs[20]==0 && m_pairs[15]==0){
			simplified=simplified+"ab'c + ";
		}
	}
	if(m_pairs[24]==1){
		if(m_pairs[25]==0 && m_pairs[27]==0 && m_pairs[16]==0){
			simplified=simplified+"a'b'd' + ";
		}
	}
	if(m_pairs[25]==1){
		if(m_pairs[24]==0 && m_pairs[26]==0 && m_pairs[17]==0){
			simplified=simplified+"a'bd' + ";
		}
	}
	if(m_pairs[26]==1){
		if(m_pairs[25]==0 && m_pairs[27]==0 && m_pairs[18]==0){
			simplified=simplified+"abd' + ";
		}
	}
	if(m_pairs[27]==1){
		if(m_pairs[26]==0 && m_pairs[24]==0 && m_pairs[19]==0){
			simplified=simplified+"ab'd' + ";
		}
	}
	if(m_pairs[28]==1){
		if(m_pairs[29]==0 && m_pairs[31]==0 && m_pairs[1]==0){
			simplified=simplified+"b'c'd' + ";
		}
	}
	if(m_pairs[29]==1){
		if(m_pairs[30]==0 && m_pairs[28]==0 && m_pairs[4]==0){
			simplified=simplified+"b'c'd + ";
		}
	}
	if(m_pairs[30]==1){
		if(m_pairs[29]==0 && m_pairs[31]==0 && m_pairs[7]==0){
			simplified=simplified+"b'cd + ";
		}
	}
	if(m_pairs[31]==1){
		if(m_pairs[30]==0 && m_pairs[28]==0 && m_pairs[10]==0){
			simplified=simplified+"b'cd' + ";
		}
	}
	if(m[0]==1){
		if(m[1]==0 && m[2]==0 && m[4]==0 && m[8]==0){
			simplified=simplified+"a'b'c'd' + ";
		}
	}
	if(m[1]==1){
		if(m[0]==0 && m[3]==0 && m[5]==0 && m[9]==0){
			simplified=simplified+"a'bc'd' + ";
		}
	}
	if(m[3]==1){
		if(m[1]==0 && m[2]==0 && m[7]==0 && m[11]==0){
			simplified=simplified+"abc'd' + ";
		}
	}
	if(m[2]==1){
		if(m[3]==0 && m[0]==0 && m[6]==0 && m[10]==0){
			simplified=simplified+"ab'c'd' + ";
		}
	}
	if(m[4]==1){
		if(m[0]==0 && m[5]==0 && m[6]==0 && m[12]==0){
			simplified=simplified+"a'b'c'd + ";
		}
	}
	if(m[5]==1){
		if(m[4]==0 && m[7]==0 && m[1]==0 && m[13]==0){
			simplified=simplified+"a'bc'd + ";
		}
	}
	if(m[7]==1){
		if(m[5]==0 && m[6]==0 && m[3]==0 && m[15]==0){
			simplified=simplified+"abc'd + ";
		}
	}
	if(m[6]==1){
		if(m[7]==0 && m[4]==0 && m[2]==0 && m[14]==0){
			simplified=simplified+"ab'c'd + ";
		}
	}
	if(m[12]==1){
		if(m[4]==0 && m[13]==0 && m[14]==0 && m[8]==0){
			simplified=simplified+"a'b'cd + ";
		}
	}
	if(m[13]==1){
		if(m[12]==0 && m[15]==0 && m[5]==0 && m[9]==0){
			simplified=simplified+"a'bcd + ";
		}
	}
	if(m[15]==1){
		if(m[13]==0 && m[14]==0 && m[7]==0 && m[11]==0){
			simplified=simplified+"abcd + ";
		}
	}
	if(m[14]==1){
		if(m[15]==0 && m[12]==0 && m[6]==0 && m[10]==0){
			simplified=simplified+"ab'cd + ";
		}
	}
	if(m[8]==1){
		if(m[9]==0 && m[10]==0 && m[0]==0 && m[12]==0){
			simplified=simplified+"a'b'cd' + ";
		}
	}
	if(m[9]==1){
		if(m[8]==0 && m[11]==0 && m[13]==0 && m[1]==0){
			simplified=simplified+"a'bcd' + ";
		}
	}
	if(m[11]==1){
		if(m[9]==0 && m[10]==0 && m[15]==0 && m[3]==0){
			simplified=simplified+"abcd' + ";
		}
	}
	if(m[10]==1){
		if(m[11]==0 && m[8]==0 && m[2]==0 && m[14]==0){
			simplified=simplified+"ab'cd' + ";
		}
	}
	/*int j;
	for(int i=0;simplified[i]!='\0';i++) ++j;
	j--;
	simplified[j]=" ";*/
	cout<<"\nThe simplified function is: "<<simplified;
	return 0;
}
