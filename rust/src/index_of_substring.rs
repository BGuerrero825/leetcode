struct Solution {
    ans: i32,
}

impl Solution {
    pub fn str_str(haystack: String, needle: String) -> i32 {

        let index = haystack.find(&needle);
        if index == None {
            return -1;
        }
        return index.unwrap() as i32;
    }

    pub fn str_str2(haystack: String, needle: String) -> i32 {

        let nlen = needle.len();
        let hlen = haystack.len();
    
        if nlen > hlen {
            return -1;
        }

        for i in 0..hlen-nlen {
            if haystack[i..i+nlen] == needle {
                return i as i32;
            }
        }

        -1
    }
}