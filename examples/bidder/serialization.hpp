/* 
 * File:   serialization.hpp
 * Author: arseny.bushev@gmail.com
 *
 * Created on 16 февраля 2017 г., 21:24
 */

#ifndef BIDDER_SERIALIZATION_HPP
#define BIDDER_SERIALIZATION_HPP

#include <boost/serialization/set.hpp>
#include <boost/serialization/vector.hpp>

#include "geo_campaign.hpp"
#include "campaign_data.hpp"
#include "ad.hpp"
#include "geo_ad.hpp"
#include "geo.hpp"

//Non-Intrusive boost serialization implementation
namespace boost { namespace serialization {
    template<class Archive>
    void serialize(Archive & ar, Ad & value, const unsigned int version) {
        ar & value.ad_id;
        ar & value.width;
        ar & value.height;
        ar & value.position;
        ar & value.max_bid_micros;
        ar & value.code;
        ar & value.record;
    }
    template<class Archive>
    void serialize(Archive & ar, GeoAds & value, const unsigned int version) {
        ar & value.geo_id;
        ar & value.ad_ids;
    }
    template<class Archive>
    void serialize(Archive & ar, Geo & value, const unsigned int version) {
        ar & value.geo_id;
        ar & value.city;
        ar & value.country;
        ar & value.record;
    }
    template<class Archive>
    void serialize(Archive & ar, GeoCampaigns & value, const unsigned int version) {
        ar & value.geo_id;
        ar & value.campaign_ids;
    }
    template<class Archive>
    void serialize(Archive & ar, CampaignData & value, const unsigned int version) {
        ar & value.campaign_id;
        ar & value.ad_ids;
    }
}} 

#endif /* BIDDER_SERIALIZATION_HPP */

