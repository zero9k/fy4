 // TIE@FY3
inherit SKILL;
void setup(){
        set("name", "���������޷�");
        set("usage/whip", 1);
        set("usage/parry", 1);
        set("effective_level", 180);
        set("learn_bonus", -40);
        set("practice_bonus", -20);
        set("black_white_ness", 40);
        set("skill_class", "shaolin");
        set("parry_msg", ({
        "$nʹ��һ�С�˫�����������ȡ�����׮վ�ȣ����㲻������׼$N�����ƣ�����$vһ�������$w��\n",
                "$nһ�С����ķ������������������������$vӭ��$N��$w�����$N˫�����飬$w��Щ���֡�\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$n����$v�ն������ν�����һ�С��ŵ��޸���ƮƼ��������$N�Ĺ���Ʈ����\n",
        "$n�����Ҷ���$v���գ�һ�С��ų���;�����١�����ȴת��$N������\n",
        }) );
        action = ({
                ([
                        "action":               
                        "$N����$w�ն����޷���ӿ��ȥʽ��������һ�С����ƺ�����������ֱ��$n��$l��",
                        "dodge":                500,
                        "parry" :               500,
                        "force" :               500,
                        "damage_type":  "����"
                ]),
        ([
            "action":               
            "$N�۽�����һ˿Ц��,����$wȦ����һ�С���������Ц������������$n��$l��",
            "dodge":                300,
            "parry" :               300,
            "force" :               300,
            "damage_type":  "����"
        ]),
        ([
            "action":               
            "$N����$w���ڣ����μ�����һ�С����ܵǳ�����Ϸ�������ó�������Ӱ��ֱ��$n��$l��",
            "dodge":                500,
            "parry" :               500,
            "force" :               400,
            "damage_type":  "����"
        ]),
        ([
            "action":              
            "$N����$w����������ת��һ�С�����˭�����˹������ޱ޽Դ���$n��$l��",
            "dodge":                700,
            "parry" :               700,
            "force" :               700,
            "damage_type":  "����"
        ]),
        ([
            "action":               
            "$N����$w��ͷһ�ޣ������ű���һ�ڣ�һ�С�һ�����󷽷����������ó�����Ӱ����$nΧ�����У�",
            "dodge":                500,
            "parry" :               500,
            "force" :               600,
            "damage_type":  "����"
        ]),
        ([
            "action":               
            "$N����$wȦȦ��㣬�������࣬һ�С�������ʱ�����ԡ�������ʵʵ��$n��$l��ȥ��",
            "dodge":                700,
            "parry" :               700,
            "force" :               300,
            "damage_type":  "����"
        ]),
        ([
            "action":               
            "$Nʹ��һ�С������������뾻������ͷֱֱ����$n��$l��",
            "dodge":                700,
            "parry" :               700,
            "force" :               100,
            "damage_type":  "����"
    ]),
        ([
            "action":               
            "$N����$wӭͷ��ȥ�����Ұڶ���һ�С�δ��֪����֪�ա�������$n�ĵ����������",
            "dodge":                300,
            "parry" :               300,
            "force" :               700,
            "damage_type":  "����"
        ]), 
        });
}
int valid_learn(object me)
{
        if( (int)me->query("max_force") < 150 ){
                return notify_fail("�������������û�а취�����������޷�������Щ���������ɡ�\n");
        }
        if(!::valid_learn(me)){
                return 0;
        }
        return 1;
} 
int practice_skill(object me)
{
        if((int)me->query("force") < 10 ){
                return notify_fail("�����������������û�а취��ϰ���������޷���\n");
        }
        if(!::practice_skill(me)){
                return 0;
        }
        me->add("force", -10);
        write("�㰴����ѧ����һ�����������޷���\n");
        return 1;
}     