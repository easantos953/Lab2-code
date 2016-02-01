module reg32( clk, reset_n, D, byteenable, Q);

//parameter byte_width = 8;
input [31:0] D;
input [3:0] byteenable;
output reg [31:0] Q;
input clk;
input reset_n;

always@(posedge clk)
	if(!reset_n)
		Q <= 32'b0;
	else
	begin
		if (byteenable[0]) Q[7:0] <= D[7:0];
		if (byteenable[1]) Q[15:8] <= D[15:8];
		if (byteenable[2]) Q[23:16] <= D[23:16];
		if (byteenable[3]) Q[31:24] <= D[31:24];
	end
endmodule	
/*		
reg [byte_width-1:0] di3,di2,di1,di0; 
reg [31:0] Q;

always@(byteenable or D)
	begin
		if(byteenable[3])
			di3 = D[4*byte_width-1:3*byte_width]; //4th byte [31-24]
		if(byteenable[2])
			di2 = D[3*byte_width-1:2*byte_width]; //3rd byte [23-16]
		if(byteenable[1])
			di1 = D[2*byte_width-1:1*byte_width]; //2nd byte [15-7]
		if(byteenable[0])
			di0 = D[1*byte_width-1:0*byte_width]; //1st byte [7-0]
	end
			
			
always @(posedge clk)

begin
if (reset_n) 
Q <= 0;
else
	Q <= {di3,di2,di1,di0};
end


endmodule
*/
