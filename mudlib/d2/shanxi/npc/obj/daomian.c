 inherit F_FOOD;
inherit ITEM; 
void create()
{
        set_name("������", ({ "dao mian", "mian" }) );
        set_weight(350);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "��԰�ﷹ�ݵĵ����棬����������ϸ���ȣ���Ҷ�Σ�����ˬ�ڡ�\n");
                set("unit", "��");
                set("value", 2000);
                set("food_remaining", 5);
                set("food_supply", 60);
                set("material", "food");
        }
        ::init_item();
}
int finish_eat()
{
        set_name("��̩������", ({"wan"}));
        set("value",200);
        set("long", "һֻ��̩�����롣\n");
        return 1;
} 
