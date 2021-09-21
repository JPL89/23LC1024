# 23LC1024

nokia5110.Init();

MEM memory;<br />
	
memory.Serial_Init();<br />
	
memory.Write_Block(0, 127);<br />
	
char data = memory.Read_Block(0);<br />

nokia5110.WriteInt(data, 0, 0, Font_Arial_16x16);<br />

<img align="left" width="390" height="600" src="https://github.com/josimarpereiraleite/23LC1024/blob/main/Images/0.png"><br />
<br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br />
<br /><br /><br /><br /><br /><br /><br /><br />
