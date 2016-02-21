 mapping inquiry_msg = ([
                "张猎户":       "张猎户善能驱使虎豹，远近闻名。\n",
                "安子豪":       "安子豪是镇上驿站的长官，也是这儿的地方官。",
                "铁恨"  :       "铁恨是天下闻名的四大名捕之铁手无情。",
                "武镇山" :      "武镇山武三爷，太平镇这地方有一半是他的。",
                "武三爷" :      "武镇山武三爷，太平镇这地方有一半是他的。",
                "李大娘" :      "没有人知道大娘真名叫什么，只知道她三年前在镇旁买下了座庄园。",
                "老蛔虫" :      "三年前老蛔虫盘下了这里的杂货铺，没有人知道他从哪里来。",
                "谭氏兄弟" :    "谭氏兄弟是上个月才到的，租下了杂货铺旁边的大宅，除了吃饭很少出门。",
                "宋妈妈" :      "宋大娘是鹦鹉楼的鸨母，不过她经常呆在自己的黑屋子里。",
                "老掌柜":       "老掌柜是客站的老板，据说他一个晚上在鹦鹉楼花完了一辈子的积蓄。",
                "血奴" :        "血奴是这儿鹦鹉楼的头块牌子。",
                "常笑":         "毒剑常笑心狠手辣，他今年不过三十六岁，做这份工作不过十年，死\n在他手上的人却已过千。",
]);  
string query_inquiry_msg(string arg) {
        string *msg;
        int i;  
        msg=keys(inquiry_msg);
        for (i=0;i<sizeof(msg);i++) 
                if (msg[i]==arg) return inquiry_msg[msg[i]];
        return 0;
}            
