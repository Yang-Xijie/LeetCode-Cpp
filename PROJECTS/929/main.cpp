// [info]

// https://leetcode.cn/problems/unique-email-addresses/
// 每个有效电子邮件地址都由一个本地名和一个域名组成，以 '@' 符号分隔。
// 除小写字母之外，电子邮件地址还可以含有一个或多个 '.' 或 '+'
// 给你一个字符串数组 emails，我们会向每个 emails[i]
// 发送一封电子邮件。返回实际收到邮件的不同地址数目。

// References: 
// [CSDN | C++中string的用法](https://blog.csdn.net/qq_30534935/article/details/82227364)

// [include]

#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>

// [solution]

struct DomainBox {
  std::string domain_name;
  std::vector<std::string> local_names;
};

class Solution {
 public:
  int numUniqueEmails(std::vector<std::string>& emails) {
    std::vector<DomainBox> database;

    for (unsigned long i = 0; i < emails.size(); i++) {  // for each email
      std::string email = emails[i];
      unsigned long plus_position = email.find('+');
      std::string local_name = email.substr(0, plus_position);
      unsigned long at_position = email.find('@');
      std::string domain_name = email.substr(at_position + 1);

      for (int l = int(local_name.length()) - 1; l >= 0;
           l--) {  // for each letter
        if (local_name[l] == '.') {
          local_name.erase(l, 1);
        }
      }

      // printf("%s %s\n", local_name.c_str(), domain_name.c_str());

      bool already_has_domain = false;
      for (int k = 0; k < int(database.size()); k++) {
        if (domain_name.compare(database[k].domain_name) == 0) {
          already_has_domain = true;

          bool alread_has_local = false;
          for (int k = 0; k < int(database[k].local_names.size()); k++) {
            if (local_name.compare(database[k].local_names[k]) == 0) {
              alread_has_local = true;
              break;
            }
          }
          if (!alread_has_local) {
            database[k].local_names.push_back(local_name);
          }

          break;
        }
      }
      if (!already_has_domain) {
        DomainBox domainBox = DomainBox();
        domainBox.domain_name = domain_name;
        bool alread_has_local = false;
        for (int k = 0; k < int(domainBox.local_names.size()); k++) {
          if (local_name.compare(domainBox.local_names[k]) == 0) {
            alread_has_local = true;
            break;
          }
        }
        if (alread_has_local) {
          domainBox.local_names.push_back(local_name);
        }
        database.push_back(domainBox);
      }
    }

    return database.size();
  }
};

// [main]

int main() {
  printf("[TRACE] START\n");

  // [set input]
  std::vector<std::string> emails = {"tes..t.email+alex@leetcode.com",
                                     "test.e.mail+bob.cathy@leetcode.com",
                                     "testemail+david@lee.tcode.com"};

  // [call solution]
  int result = Solution().numUniqueEmails(emails);

  // [verify result]
  printf("result = %d\n", result);

  printf("[TRACE] END\n");
}
