#include <ansi.h>
inherit SKILL;
mapping *quest = ({
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "exp_bonus":            35,
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "exp_bonus":            35,
        ]),
        ([      "quest":                "���²���",
                "quest_type":           "ɱ",
                "exp_bonus":            35,
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "exp_bonus":            35,
        ]),
        ([      "quest":                "һ������",
                "quest_type":           "Ѱ",
                "time":                 360,
                "exp_bonus":            25,
        ]),
        ([      "quest":                "�������",
                "quest_type":           "Ѱ",
                "exp_bonus":            35,
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "exp_bonus":            35,
        ]),
        ([      "quest":                "�ձ�����",
                "quest_type":           "ɱ",
                "exp_bonus":            35,
        ]),
        ([      "quest":                "С��",
                "quest_type":           "ɱ",
                "exp_bonus":            40,
        ]),
        ([      "quest":                "�廨Ь",
                "quest_type":           "Ѱ",
                "exp_bonus":            35,
        ]),
        ([      "quest":                "�ۺ���",
                "quest_type":           "Ѱ",
                "exp_bonus":            35,
        ]),
        ([      "quest":                "ϸ÷��",
                "quest_type":           "Ѱ",
                "exp_bonus":            35,
        ]),
        ([      "quest":                "��ʿ",
                "quest_type":           "ɱ",
                "exp_bonus":            35,
        ]),
        ([      "quest":                "��ľ��",
                "quest_type":           "Ѱ",
                "exp_bonus":            35,
        ]),
        ([      "quest":                "л����",
                "quest_type":           "ɱ",
                "time":                 840,
                "exp_bonus":            45,
        ]),
        ([      "quest":                "�γ���",
                "quest_type":           "ɱ",
                "exp_bonus":            35,
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "exp_bonus":            35,
        ]),
        ([      "quest":                "���",
                "quest_type":           "ɱ",
                "exp_bonus":            35,
        ]),
        ([      "quest":                "±ζ��",
                "quest_type":           "Ѱ",
                "exp_bonus":            35,
        ]),
        ([      "quest":                "�Ź���",
                "quest_type":           "ɱ",
                "exp_bonus":            35,
        ]),
        ([      "quest":                "ߡ��",
                "quest_type":           "Ѱ",
                "exp_bonus":            35,
        ]),
        ([      "quest":                "���ĸ",
                "quest_type":           "ɱ",
                "exp_bonus":            35,
        ]),
        ([      "quest":                "�������",
                "quest_type":           "Ѱ",
                "exp_bonus":            35,
        ]),
        ([      "quest":                "Сè��",
                "quest_type":           "ɱ",
                "exp_bonus":            30,
        ]),
        ([      "quest":                "С����",
                "quest_type":           "ɱ",
                "exp_bonus":            30,
        ]),
        ([      "quest":                "֪�͵���",
                "quest_type":           "ɱ",
                "exp_bonus":            45,
        ]),
        ([      "quest":                "��ɫ����",
                "quest_type":           "Ѱ",
                "exp_bonus":            35,
        ]),
        ([      "quest":                "�಼����",
                "quest_type":           "Ѱ",
                "exp_bonus":            35,
        ]),
        ([      "quest":                "��Ө",
                "quest_type":           "ɱ",
                "exp_bonus":            40,
        ]),
        ([      "quest":                "��ɺ",
                "quest_type":           "ɱ",
                "exp_bonus":            40,
        ]),
        ([      "quest":                "������",
                "quest_type":           "Ѱ",
                "exp_bonus":            35,
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "exp_bonus":            35,
        ]),
        ([      "quest":                "ˮ���",
                "quest_type":           "ɱ",
                "exp_bonus":            45,
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "exp_bonus":            35,
        ]),
        ([      "quest":                "��³����Ů",
                "quest_type":           "ɱ",
                "exp_bonus":            35,
        ]),
        ([      "quest":                "�մ�",
                "quest_type":           "ɱ",
                "exp_bonus":            45,
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "exp_bonus":            40,
        ]),
        ([      "quest":                "�޲�����ɮ��",
                "quest_type":           "Ѱ",
                "exp_bonus":            45,
        ]),
        ([      "quest":                "�����ر�",
                "quest_type":           "Ѱ",
                "exp_bonus":            35,
        ]),
        ([      "quest":                "��������",
                "quest_type":           "ɱ",
                "exp_bonus":            35,
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "exp_bonus":            35,
        ]),
        ([      "quest":                "ţͷ",
                "quest_type":           "ɱ",
                "exp_bonus":            35,
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "exp_bonus":            35,
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "exp_bonus":            35,
        ]),
        ([      "quest":                "ɳ����",
                "quest_type":           "ɱ",
                "exp_bonus":            35,
        ]),  
});
mapping query_quest()
{
        return quest[random(sizeof(quest))];
}      
