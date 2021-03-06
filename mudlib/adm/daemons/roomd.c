// roomd.c
#include <room.h>

string dir_chinese(string dir);
object get_neighbour(object where,string dir);
string room_direction(object where,string filename);
string anti_dir(string dir);

void create() { seteuid(getuid()); }

object get_neighbour(object where,string dir)
{
mapping direction;
int i,have_dir=0;
string *dire,filename;
object neighbour;
if(!direction=where->query("exits"))
	return 0;
dire=keys(direction);
for(i=0,have_dir=0;i<sizeof(dire);i++)
	{
	if(dire[i]==dir)
		{
		filename=direction[dire[i]];
		if(neighbour=find_object(filename));
			return neighbour;
		call_other(filename,"???");
		neighbour=find_object(dir);
		return neighbour;
		}
	}
}

string room_derection(object where,string filename)
{
mapping direction;
string	*dire,dir;
int i;
if(!direction=where->query("exits"))
	return NO_SUCH_DIRECTION;
dire=keys(direction);
for(i=0;i<sizeof(dire);i++)
	{
	if(filename==direction[dire[i]])
		return dire[i];
	}
return NO_SUCH_DIRECTION;
}
	
string dir_chinese(string dir)
{
switch(dir)
{
case	"east" : return "东面" ;
case  	"west" : return "西面" ;
case	"north" : return "北面" ;
case	"south" : return "南面" ;
case	"enter" : return "里面" ;
case	"out" : return "外面" ;
case	"southeast" : return "东南面";
case	"northwest" : return "西北面";
case	"southwest" : return "西南面";
case	"northeast" : return "东北面";
case	"northup"   : return "北上方";
case	"eastup"    : return "东上方";
case    "southup"   : return "南上方";
case 	"westup"    : return "西上方";
case	"up"        : return "上面";
case	"down"	    : return "下面";
case    "eastdown"  : return "东下方";
case    "westdown"  : return "西下方";
case    "southdown" : return "南下方";
case    "northdown" : return "北下方";
default :	return dir;
}
}

string anti_dir(string dir)
{
string dir1=dir;
if(dir=="east") return "west";
if(dir=="west") return "east";
if(dir=="south") return "north";
if(dir=="north") return "south";
if(dir=="up") return "down";
if(dir=="down") return "up";
if(dir=="northeast") return "southwest";
if(dir=="northwest") return "southeast";
if(dir=="southeast") return "northwest";
if(dir=="southwest") return "northeast";

return dir1;
}
