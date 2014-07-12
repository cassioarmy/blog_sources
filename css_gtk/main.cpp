#include <iostream>
#include <gtkmm-3.0/gtkmm.h>

using namespace std;

int main(int argc, char **argv) {
      Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "org.gtkmm.exampleCSS");
	
      Glib::RefPtr<Gtk::Builder> refBuilder = Gtk::Builder::create();
      try{
        refBuilder->add_from_file( "main.glade" );
        
      }catch(const Gtk::BuilderError& ex){
          std::cerr << "FileError: " << ex.what() << std::endl;
	  return 1;
      }catch(const Glib::FileError& ex){
        std::cerr << "FileError: " << ex.what() << std::endl;
	return 1;
      }

      Gtk::ApplicationWindow* appWindow ;
      
      refBuilder->get_widget("appWindow", appWindow);
      cout << app->register_application();
	
      app->run(*appWindow);

      delete appWindow;

      return 0;
}
