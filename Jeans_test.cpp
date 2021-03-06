/**
 *  Fill the (...) below in such a way that Collection objects are created.
 *  Use aliases CollectionJN for Collection of Jeans.
 *  Implement Operator>> (identical to the one you did for Stress_ball in PA1-p2) for Collection of Jeans.
 *  This file needs to be uploaded to Mimir.
 * 
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include "Jeans.h"
#include "Collection.h"

using CollectionJN = Collection<Jeans, Jeans_colors, Jeans_sizes>;

istream& operator>>(istream& is, CollectionJN& c){
	std::string clr;
	std::string sz;
	Jeans_colors color;
	Jeans_sizes size;
	
	while (!is.eof()) {
		is >> clr >> sz;
		
		if (clr == "white") {
			color = static_cast<Jeans_colors>(0);
		} else if (clr == "black") {
			color = static_cast<Jeans_colors>(1);
		} else if (clr == "blue") {
			color = static_cast<Jeans_colors>(2);
		} else if (clr == "grey") {
			color = static_cast<Jeans_colors>(3);
		}
		
		if (sz == "small") {
			size = static_cast<Jeans_sizes>(0);
		} else if (sz == "medium") {
			size = static_cast<Jeans_sizes>(1);
		} else if (sz == "large") {
			size = static_cast<Jeans_sizes>(2);
		} else if (sz == "xlarge") {
			size = static_cast<Jeans_sizes>(3);
		}
			
		Jeans sb(color, size);
			
		c.insert_item(sb);
	}
		
	return is;
}
void test_jeans(){
        Jeans jeans_1 = Jeans(Jeans_colors::grey, Jeans_sizes::small);
        Jeans jeans_2 = Jeans(Jeans_colors::grey, Jeans_sizes::large);
        Jeans jeans_3 = Jeans(Jeans_colors::blue, Jeans_sizes::large);
        CollectionJN collection_0;
        CollectionJN collection_1;
        CollectionJN collection_2(3);
        CollectionJN collection_3(5);
        CollectionJN collection_file(1);
        collection_0.insert_item(jeans_1);
        collection_0.make_empty();
        collection_1.insert_item(jeans_1);
        collection_2.insert_item(jeans_2);
        
        collection_2.print_items();
        collection_2.insert_item(Jeans(Jeans_colors::blue, Jeans_sizes::small));
        collection_2.insert_item(jeans_3);
        collection_2.insert_item(jeans_3);
        CollectionJN collection_copy(collection_1);
        collection_1.insert_item(Jeans(Jeans_colors::black, Jeans_sizes::small));
        CollectionJN collection_7 = move(collection_1);
        collection_2.insert_item(Jeans(Jeans_colors::blue, Jeans_sizes::medium));
        collection_2.insert_item(Jeans(Jeans_colors::grey, Jeans_sizes::large));
        collection_2.insert_item(Jeans(Jeans_colors::grey, Jeans_sizes::large));
        collection_2.remove_this_item(jeans_2);
        
        collection_2.print_items();
        collection_copy.make_empty();
        if(collection_2.is_empty()){
            collection_2.insert_item(Jeans(Jeans_colors::black, Jeans_sizes::small));
        }
        ifstream ifs("jeans1.data");
        ifs >> collection_file;
        collection_file.insert_item(jeans_3);
        collection_file.insert_item(jeans_3);
        collection_2.insert_item(jeans_3);
        collection_2.insert_item(jeans_3);
        collection_2.insert_item(jeans_2);
        collection_2.insert_item(jeans_1);
        collection_file.print_items();

        swap(collection_file,collection_2);

        collection_3 = make_union(collection_file,collection_2);                
        cout<<collection_3;
		cout << "Jeans tests passed!" << endl;
}
