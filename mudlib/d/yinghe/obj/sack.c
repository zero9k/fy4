 inherit ITEM;
void create()
{
   set_name("���", ({ "sack" , "���", "madai", "ma dai"}) );
   set_weight(500);
   set_max_encumbrance(80000);
   set("no_get", 1);
   set("no_shown", 1);
   if( clonep() )
      set_default_object(__FILE__);
   else {
      set("prep", "in");
      set("unit", "��");
      set("long", "һ��������� \n");
      set("value", 1);
   }
    ::init_item();
} 
int is_container() { return 1; }        
