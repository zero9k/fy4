 // updated.c
#define f_price "/obj/prize/f_p.c"
#define s_price "/obj/prize/s_p.c"
#define t_price "/obj/prize/t_p.c"
void checkrace(object ob);
void loadall(object me);
void create() { seteuid(getuid()); }
void check_user(object ob)
{
        mapping my;
        string user_class;
        int tmp, dorm_force;
      
        
//      checkrace(ob);
        if( !ob->query_temp("already_loaded"))
      {
    
                loadall(ob);
      }       
// implemented to have menpai marks.
        user_class=ob->query("class");
        ob->set("once_menpai/"+user_class, 1); 
// following is to 弥补以前不完善的纪录。所有的+内力/法力/魔力都将记录在Add_force/Add_mana/Add_atman中，
// 在human.c中将自动把这部分数值叠加到相应的地方。       
        if (ob->query("marks/3years_force"))                    // 华山青青 riddle
                ob->set("Add_force/3years_force",100);
        if ( dorm_force = ob->query_skill("dormancy",1)) {      // 铁雪 dormancy加气。
                if ( dorm_force >= 200 )  
                        ob->set("Add_force/dormancy",ob->query("class") == "legend" ? 350 : 200);
                else if (dorm_force >= 190 )    
                        ob->set("Add_force/dormancy",ob->query("class") == "legend" ? 250 : 100);
                else if (dorm_force >= 180 )    
                        ob->set("Add_force/dormancy",50);
        }                       
        
        
        if(!wizardp(ob))
        {
                ob->delete("env/invisibility");
                ob->delete("env/immortal");
        }
   my = ob->query_entire_dbase();
        if( undefinedp(my["eff_gin"]) ) my["eff_gin"] = my["max_gin"];
        if( undefinedp(my["eff_kee"]) ) my["eff_kee"] = my["max_kee"];
        if( undefinedp(my["eff_sen"]) ) my["eff_sen"] = my["max_sen"];
        if( my["eff_gin"] > my["max_gin"] ) my["eff_gin"] = my["max_gin"];
        if( my["eff_kee"] > my["max_kee"] ) my["eff_kee"] = my["max_kee"];
        if( my["eff_sen"] > my["max_sen"] ) my["eff_sen"] = my["max_sen"];
        if( my["gin"] > my["eff_gin"] ) my["gin"] = my["eff_gin"];
        if( my["kee"] > my["eff_kee"] ) my["kee"] = my["eff_kee"];
        if( my["sen"] > my["eff_sen"] ) my["sen"] = my["eff_sen"];
        
        if( !( my["age"] % 5 ) && my["age"] <=55 ) my["gift_points"] = my["age"] - 5; 
// donation time!!
        if( my["deposit"]/10000000 > (my["age"]-10))
        {
                write("钱庄被山西抢匪掠洗一空！你损失了"
                + chinese_number(my["deposit"]-(my["age"]-10)*10000000) +"文钱．\n");
                my["deposit"] -= (my["deposit"]-(my["age"]-10)*10000000);
        }
}   
void checkrace(object ob)
{
        object reward;
        int title_race;
        title_race = (int) ob->query("title_race");
        if (title_race == 1)
        {
                reward = new(f_price);
                reward->move(ob);
                ob->set("title_race", -1);
        }
        if (title_race == 2)
        {
                reward = new(s_price);
                reward->move(ob);
                ob->set("title_race", -2);
        }
        if (title_race == 3)
        {
                reward = new(t_price);
                reward->move(ob);
                ob->set("title_race", -3);
        }
        return;
} 
void loadall(object me)
{
        int MAX = 5;
        string name,id, *created;
        int j;
        object thing;
        id = me->query("id");
        created = get_dir(DATA_DIR + "login/" + id[0..0] + "/" + id + "/");
        write("\n\n");
        for(j=0; (j<sizeof(created) && j < (MAX+1) ); j++)
        if( sscanf(created[j], "%s.c", name) == 1 )
                {
                        thing = new( DATA_DIR + "login/" + id[0..0] + "/" + id + "/" + name + ".c");
                        write( thing->name() + "\n");
                        thing->restore();
                        if(thing->move(me))  write("ＯＫ．\n\n");
                }
        me->set_temp("already_loaded",1);
            
}      
