 // begging.c
inherit SKILL; 
void setup() {
        set("name",                             "姹女神功");
        set("learn_bonus",                      35);
        set("effective_level",          180);
        set("type", "knowledge");
        set("skill_class",              "shenshui");
}  
int valid_learn(object me) {
        if(!::valid_learn(me)) {
                return 0;
        }
        if((string)me->query("class") != "shenshui" ) 
                return notify_fail("姹女神功是神水宫弟子独有的武功。\n");
        return 1;
}
