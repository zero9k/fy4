inherit ITEM;
void create()
{
        set_name( "�Ҷ���ţͼ��", ({ "xiruo book","book" }));
        set_weight(600);
        set("unit", "��");
        set("long", "���Ǹ���һ�������������Ҷ�ɱţ��������ĵ���ͼ�⡣\n");
        set("value", 100);
        set("skill", ([
                "name":                 "xiruo-blade",             // name of the skill
                //"exp_required": 20000,                              // minimum combat experience required
                                                                                // to learn this skill.
                "sen_cost":             200,                             // gin cost every time study this
                "difficulty":   200,                             // the base int to learn this skill
                                                                                // modify is gin_cost's (difficulty - int)*5%
                "max_skill":    200                              // the maximum level you can learn
                                                                                // from this object.
        ]) );
}