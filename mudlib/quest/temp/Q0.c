#include <ansi.h>
inherit SKILL;
mapping *quest = ({
        ([      "quest":                "�����õ�",
                "quest_type":           "ɱ",
                "exp_bonus":            10,
        ]),
        ([      "quest":                "Ǯ",
                "quest_type":           "Ѱ",
                "exp_bonus":            10,
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "exp_bonus":            10,
        ]),
        ([      "quest":                "�ϰ���",
                "quest_type":           "ɱ",
                "exp_bonus":            10,
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "exp_bonus":            10,
        ]),
        ([      "quest":                "��С��",
                "quest_type":           "ɱ",
                "exp_bonus":            10,
        ]),
        ([      "quest":                "��������",
                "quest_type":           "Ѱ",
                "exp_bonus":            10,
        ]),
        ([      "quest":                "ֽǮ",
                "quest_type":           "Ѱ",
                "exp_bonus":            10,
        ]),
        ([      "quest":                "��ؤ",
                "quest_type":           "ɱ",
                "exp_bonus":            10,
        ]),
        ([      "quest":                "����ؤ",
                "quest_type":           "ɱ",
                "exp_bonus":            10,
        ]),
        ([      "quest":                "���",
                "quest_type":           "ɱ",
                "exp_bonus":            10,
        ]),
        ([      "quest":                "���ľ�",
                "quest_type":           "Ѱ",
                "exp_bonus":            15,
        ]),
        ([      "quest":                "ҰѼ",
                "quest_type":           "ɱ",
                "exp_bonus":            15,
        ]),
        ([      "quest":                "�׻���",
                "quest_type":           "Ѱ",
                "exp_bonus":            15,
        ]),
        ([      "quest":                "ũ�ߵ��ϰ�",
                "quest_type":           "ɱ",
                "exp_bonus":            10,
        ]),
        ([      "quest":                "�����ɿ��С����",
                "quest_type":           "ɱ",
                "exp_bonus":            10,
        ]),
        ([      "quest":                "���ɿ�",
                "quest_type":           "Ѱ",
                "exp_bonus":            10,
        ]),
        ([      "quest":                "�岨����",
                "quest_type":           "ɱ",
                "exp_bonus":            10,
        ]),
        ([      "quest":                "�ƾɲ����ĳ���",
                "quest_type":           "Ѱ",
                "exp_bonus":            10,
        ]),
        ([      "quest":                "Ԭ��",
                "quest_type":           "ɱ",
                "exp_bonus":            10,
        ]),
        ([      "quest":                "�׳�����",
                "quest_type":           "Ѱ",
                "exp_bonus":            10,
        ]),
        ([      "quest":                "��ʯ��",
                "quest_type":           "ɱ",
                "exp_bonus":            10,
        ]),
        ([      "quest":                "����̫",
                "quest_type":           "ɱ",
                "exp_bonus":            10,
        ]),
        ([      "quest":                "ũ��Ů",
                "quest_type":           "ɱ",
                "exp_bonus":            10,
        ]),
        ([      "quest":                "��ë���",
                "quest_type":           "Ѱ",
                "exp_bonus":            10,
        ]),
        ([      "quest":                "�����",
                "quest_type":           "ɱ",
                "exp_bonus":            10,
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                 "exp_bonus":            10,
        ]),
        ([      "quest":                "С����",
                "quest_type":           "ɱ",
                "exp_bonus":            10,
        ]),
        ([      "quest":                "С��",
                "quest_type":           "ɱ",
                "exp_bonus":            10,
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "exp_bonus":            10,
        ]),
        ([      "quest":                "ţƤ��",
                "quest_type":           "Ѱ",
                 "exp_bonus":            10,
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "exp_bonus":            10,
        ]),
        ([      "quest":                "ά�����ñ",
                "quest_type":           "Ѱ",
                 "exp_bonus":            10,
        ]),
        ([      "quest":                "�޺˰�����",
                "quest_type":           "Ѱ",
                 "exp_bonus":            10,
        ]),
        ([      "quest":                "��������",
                "quest_type":           "ɱ",
                "exp_bonus":            10,
        ]),
        ([      "quest":                "������˹ȹ",
                "quest_type":           "Ѱ",
                "exp_bonus":            10,
        ]),
});
mapping query_quest()
{
        return quest[random(sizeof(quest))];
}       
