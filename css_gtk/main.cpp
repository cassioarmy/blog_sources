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
      app->register_application();


      //load css
      Glib::RefPtr<Gtk::CssProvider> cssProvider = Gtk::CssProvider::create();
      cssProvider->load_from_path("style.css");
      
      
      Glib::RefPtr<Gtk::StyleContext> styleContext = Gtk::StyleContext::create();
      
      //get default screen
      Glib::RefPtr<Gdk::Screen> screen = Gdk::Screen::get_default();
      
      //add provider for screen in all application
      styleContext->add_provider_for_screen(screen,cssProvider,GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
	
      app->run(*appWindow);

      delete appWindow;

      return 0;
}
