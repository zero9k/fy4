// renwu.c for player interactive jobs.
// Keinxin@sj2  2003.3



#include <ansi.h>

#define TIME_TICK (time()*60)

string get_place(string str);
string ppl;


mapping get_renwu(object ob, string type, string family, string gender)
{
        object *obs = filter_array(objects(), (: interactive :));
        int bonus;
        int i = sizeof(obs), j = 10;
        string *arg;
        
        if (i < 1) return 0;
        while (j--) {
                ob = obs[random(i)];
                if (wiz_level(ob)) continue;       //过滤巫师
                if (ob->is_ghost()) continue;      //过滤鬼魂
                if (ob->query("combat_exp")< 60000 ) continue;      //过滤exp<60k的id
                if (!environment(ob)) continue;            //过滤断线的id
                if (ob->query("id") == ppl) continue;      //过滤刚被选中的id
                arg = explode(base_name(environment(ob)), "/");      //过滤处在最后乐园的id
                if ( arg[0] != "d" || arg[1] == "wizard" || arg[1] == "wuguan") continue;   //过滤武馆等处的id
                break;
        }
        if (j < 0) return 0;
        ppl = ob->query("id");
        
// here to enoch the quest   自动传回quest mapping数据
        bonus = 150+random(150);
        type = "劝降";           //default 为zm job劝降，可以增加其他job
                return ([ 
                "id":           (string)ob->query("id"),
                "name":         (string)ob->name(1),
                "time":         TIME_TICK+(200*30*60),
                "exp_reward":   bonus/8 + random(bonus/8),         
                "pot_reward":   bonus,
                "type":         type,
                "place":        get_place(base_name(environment(ob)))+environment(ob)->query("short"),
                ]);

}




string get_time(int i)
{
        return CHINESE_D->chinese_date(i);
}

string get_place(string str)       //传回区域所在
{

        string *place = explode(str, "/");

        str = " ";
        if(place[0] == "d")
                switch(place[1]){
                        case "baituo":  str = "西域白陀山"; break;
                        case "hj":      str = "西域回疆"; break;
                        case "mingjiao":str = "西域明教"; break;
                        case "shaolin": str = "河南嵩山少林"; break;
                        case "songshan":str = "河南嵩山"; break;
                        case "wudang":  str = "湖北武当山"; break;
                        case "xingxiu": str = "西域星宿海"; break;
                        case "city":    str = "江南扬州城"; break;
                        case "emei":    str = "四川峨嵋山"; break;
                        case "fuzhou":  str = "南疆福州"; break;
                        case "jiaxing": str = "江南嘉兴"; break;
                        case "taishan": str = "山东泰山"; break;
                        case "dali":    str = "西南大理国"; break;
                        case "tls":     str = "大理天龙寺"; break;
                        case "tiezhang":str = "湖南铁掌山"; break;
                        case "kunlun":  str = "昆仑山脉"; break;
                        case "fairyland":str = "昆仑山脉"; break;
                        case "xiaoyao": str = "逍遥派"; break;
                        case "gumu":    str = "终南山古墓"; break;
                        case "chengdu": str = "四川成都"; break;
                        case "huashan": str = "陕西华山"; break;
                        case "xiangyang":str = "湖北襄阳"; break;
                        case "xueshan": str = "西番大雪山"; break;
                        case "wizard":  str = "极乐世界"; break;
                        case "death":   str = "第十八层地狱"; break;
                        case "gaibang": str = "丐帮分舵"; break;
                        case "hz":      str = "江南杭州"; break;
                        case "village": str = "陕西小村"; break;
                        case "wuguang": str = "襄阳武馆"; break;
                        case "thd":     str = "东海桃花岛"; break;
                        case "gaibang": str = "丐帮分舵"; break;
        }
        return str;
}
