 for (int j = 0; j < s.length() -i-1 ; i++)
        {
        cout<<"chala ";
            int left = s[j] - '0';
            int right = s[j + 1] - '0';
            if (left < right)
            {
                int temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }