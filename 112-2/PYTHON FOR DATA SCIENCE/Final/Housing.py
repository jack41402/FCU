from bs4 import BeautifulSoup
from geopy.geocoders import Nominatim


class Housing:
    def __init__(self, item):
        self.address = self.__extract_address(item)
        self.property_name = self.__extract_property_name(item)
        self.website = self.__extract_website(item)
        self.beds = self.__extract_beds(item)
        self.price = self.__extract_price(item)
        self.latitude, self.longitude = self.__get_location(self.address)

    def __extract_address(self, item):
        address = item.find("p", class_="", attrs={"_ngcontent-ocp-c1029243701": ""})
        return address.text.strip() if address else ""

    def __extract_property_name(self, item):
        property_name = item.find("a", class_="card-anchor text-wrap")
        return property_name.text.strip() if property_name else ""

    def __extract_website(self, item):
        property_name = item.find("a", class_="card-anchor text-wrap")
        website = property_name.get("href") if property_name else "#"
        return f"https://offcampushousing.purdue.edu{website}" if website != "#" else "N/A"

    def __extract_beds(self, item):
        beds = item.find("span", class_="price-range")
        return beds.text.strip() if beds else ""

    def __extract_price(self, item):
        price = item.find("span", class_="border-left")
        return price.text.strip() if price else ""

    def __get_location(self, address):
        if address:
            try:
                print(address)
                geolocator = Nominatim(user_agent="housing_locator")
                location = geolocator.geocode(address, timeout=None)
                if location:
                    return location.latitude, location.longitude
            except Exception as e:
                print(f"Error retrieving location for address '{address}': {e}")
        return None, None

    def __repr__(self):
        return (f"Housing(address='{self.address}', property_name='{self.property_name}', "
                f"website='{self.website}', beds='{self.beds}', price='{self.price}', "
                f"latitude='{self.latitude}', longitude='{self.longitude}')")


if __name__ == '__main__':
    html_content = '''<li class="list-result-item">
        <p _ngcontent-ocp-c1029243701="">302 Vine St, West Lafayette, IN 47906</p>
        <a _ngcontent-ocp-c1029243701="" class="card-anchor text-wrap" href="/housing/property/hi-vine-by-weida-apartments/hssz8z2">Hi Vine by Weida Apartments</a>
        <span _ngcontent-ocp-c1029243701="" class="price-range">1 - 2 Beds</span>
        <span _ngcontent-ocp-c1029243701="" class="border-left">$1,199 - $1,875</span>
    </li>'''

    soup = BeautifulSoup(html_content, "html.parser")
    items = soup.find_all("li", class_="list-result-item")

    housings = [Housing(item) for item in items]

    for housing in housings:
        print(housing)
